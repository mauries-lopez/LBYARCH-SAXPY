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
	double aveTime = 0.0;

	long long int n = (long long int)pow(2, 10); //Length of vectors
	int scalarValue = 2; //A

	float *ptrX, *ptrY, *ptrZ;	//x,y,z
	ptrX = (float*) malloc(n * sizeof(float));
	ptrY = (float*) malloc(n * sizeof(float));
	ptrZ = (float*) malloc(n * sizeof(float));

	if(ptrX && ptrY && ptrZ){
		int lower = 1, upper = 100;
		for(i = 0; i < n; i++){
			*(ptrX + i) = (float)getBoundedRand(lower, upper);
			*(ptrY + i) = (float)getBoundedRand(lower, upper);
			*(ptrZ + i) = 0.0;
		}

		for(i = 0; i < 30; i++){
			int j;

			clock_t begin = clock();
				//==============================================C KERNEL CALL
				computeSAXPY(scalarValue, n, ptrX, ptrY, ptrZ);

				//==============================================ASM KERNEL CALL
				//for(j = 0; j < n; j++)  
					//*(ptrZ + j) = asmComputeSAXPY(scalarValue, *(ptrX + j), *(ptrY + j));

			clock_t end = clock();

			int k = 0;
			if(n > 10) k = 10;
			else k = (int)n;

			for (j = 0; j < k; j++) {
				printf("[%d] : a= %d, x= %.1f, y= %.1f, z= %.1f\n", j+1, scalarValue, *(ptrX + j), *(ptrY + j), *(ptrZ + j));
			}
			printf("Run #%d Time spent doing calculation for n = %lld: %lf\n", i+1, n, (double)(end - begin)/CLOCKS_PER_SEC);
			aveTime += (double)(end - begin)/CLOCKS_PER_SEC;
		}
		printf("\nAverage time for 30 executions for n = %lld is %lf\n", n, aveTime/30);
	}
	else{
		printf("something has gone horribly wrong. Most likely n was too big...");
		return 1;
	}	
	
	return 0;
}