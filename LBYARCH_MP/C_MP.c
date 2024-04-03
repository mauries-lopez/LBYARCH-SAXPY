#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/// <summary>
/// Returns a random value in between the lower and upper bounds, inclusive of both
/// </summary>
/// <param name="lower">Lower bound</param>
/// <param name="upper">Upper bound</param>
/// <returns>A random value.</returns>
int getBoundedRand(int lower, int upper){
	return rand() % (upper - lower + 1) + lower;
}

//This works perfectly, visual studio just doesn't like this and throws an error even though
//it clearly builds and works and is callable.
extern float asmComputeSAXPY(int a, float x, float y);

int main()
{
	//Initialize Variables
	int i = 0; //Counter variable
	srand(50); //Initialize seed for random func
	double sumTime_C = 0.0;
	double sumTime_ASM = 0.0;

	int exp = 26; //==============================================================EXPONENT (MANUAL INPUT)
	long long int n = (long long int)pow(2, exp); //Length of vectors
	int scalarValue = 2; //A

	float *ptrX, *ptrY, *ptrZ_C, *ptrZ_ASM;	//x,y,z
	ptrX = (float*) malloc(n * sizeof(float));
	ptrY = (float*) malloc(n * sizeof(float));
	ptrZ_C = (float*) malloc(n * sizeof(float));
	ptrZ_ASM = (float*) malloc(n * sizeof(float));

	if(ptrX && ptrY && ptrZ_C && ptrZ_ASM){
		int lower = 1, upper = 100;
		for(i = 0; i < n; i++){
			*(ptrX + i) = (float)getBoundedRand(lower, upper);
			*(ptrY + i) = (float)getBoundedRand(lower, upper);
			*(ptrZ_C + i) = 0.0;
			*(ptrZ_ASM + i) = 0.0;
		}

		for(i = 0; i < 30; i++){
			int j;

			clock_t begin_C = clock();
				//==============================================C KERNEL CALL
				computeSAXPY(scalarValue, n, ptrX, ptrY, ptrZ_C);
			clock_t end_C = clock();

			clock_t begin_ASM = clock();
				//==============================================ASM KERNEL CALL
				for(j = 0; j < n; j++)  
					*(ptrZ_ASM+ j) = asmComputeSAXPY(scalarValue, *(ptrX + j), *(ptrY + j));
			clock_t end_ASM = clock();

			int k = 0;
			if(n > 10) k = 10;
			else k = (int)n;

			for (j = 0; j < k; j++) {
				printf("\n[%-2d] : a= %-3d, x= %-5.1f, y= %-5.1f, z(C)= %-5.1lf & z(ASM)= %-5.1lf", j+1, scalarValue, *(ptrX + j), *(ptrY + j), *(ptrZ_C + j), *(ptrZ_ASM + j));
				if( *(ptrZ_C + j) == *(ptrZ_ASM + j)){
					printf("\tSANITY CHECK PASSED: BOTH EQUAL AND CORRECT (C is known correct)");
				}
				else{
					printf("OH NO! SANITY CHECK FAILED! ONE ISN'T EQUAL");
				}
			}
			printf("\nRun #%d (C): Time spent doing calculation for n = %lld(2^%d): %lf\n", i+1, n, exp, (double)(end_C - begin_C)/CLOCKS_PER_SEC);
			printf("Run #%d (ASM): Time spent doing calculation for n = %lld(2^%d): %lf\n", i+1, n, exp, (double)(end_ASM - begin_ASM)/CLOCKS_PER_SEC);
			sumTime_C += (double)(end_C - begin_C)/CLOCKS_PER_SEC;
			sumTime_ASM += (double)(end_ASM - begin_ASM)/CLOCKS_PER_SEC;
		}
		printf("\nC: Total time for 30 executions for n = %lld(2^%d) is %.8lf\n", n, exp, sumTime_C);
		printf("C: Average time is %lf\n", sumTime_C/30);
		printf("ASM: Total time for 30 executions for n = %lld(2^%d) is %.8lf\n", n, exp, sumTime_ASM);
		printf("ASM:  Average time is %lf\n", sumTime_ASM/30);

		if(sumTime_C < sumTime_ASM)
			printf("C is on average faster than ASM for n = %lld(2^%d) by %lf!", n, exp, (sumTime_ASM/30) - (sumTime_C/30));
		else
			printf("ASM is on average faster than C for n = %lld(2^%d) by %lf!", n, exp, (sumTime_C/30) - (sumTime_ASM/30));

		printf("\n\n");
	}
	else{
		printf("something has gone horribly wrong. Most likely n was too big... Your exponent was %d", exp);
		return 1;
	}	
	
	return 0;
}