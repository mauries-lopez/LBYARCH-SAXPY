#include <stdio.h>

//extern long long int sum(long long int a1, long long int a2, long long int* a3);
//extern int sub(int var1, int var2);
//extern float mul(int scalar, float vectorValue);

int main()
{
	/*
	long long int a1, a2, a3, ans;
	a1 = 512;
	a2 = 1024;
	a3 = 5;
	ans = sum(a1, a2, &a3);
	printf("%lld + %lld = %lld \n", a1, a2, ans);
	printf("new A3 value is %lld", a3);

	int var1 = 5, var2 = 5, difference = 0;
	difference = sub(var1, var2);
	printf("Answer: %d", difference);

	*/

	//Initialize Variables
	int i = 0;
	int scalarValue = 2;
	float vectorX[10] = { 1.0, 2.0, 3.0 };
	float vectorXValue = 0.0;
	float vectorY[10] = { 11.0, 12.0, 13.0 };
	float vectorYValue = 0.0;

	float ans = 0.0;
	float vectorZ[10] = { 0 };

	/*
	//Scalar Input
	printf("Scalar Value: ");
	scanf_s("%d", &scalarValue);

	//Vector X Input
	for (i = 0; i <= scalarValue; i++) {
		printf("[%d] Vector X Value: ", i);
		scanf_s("%f", &vectorXValue);
		vectorX[i] = vectorXValue;
	}

	//Vector Y Input
	for (i = 0; i <= scalarValue; i++) {
		printf("[%d] Vector Y Value: ", i);
		scanf_s("%f", &vectorYValue);
		vectorY[i] = vectorYValue;
	}
	*/

	//Compute SAXPY
	for (i = 0; i <= scalarValue; i++) {
		ans = (scalarValue * vectorX[i]) + vectorY[i];
		vectorZ[i] = ans;
	}

	//Check Values
	for (i = 0; i <= scalarValue; i++) {
		printf("\n[%d] : %.1f", i, vectorZ[i]);
	}
	
	return 0;
}