#include<stdio.h>
#include<stdlib.h>

#define COLS 10000
#define ROWS 10000

int sum_array_rows(int** a)
{
	int i, j, sum = 0;

	for (i = 0; i < COLS; i++)
		for (j = 0; j < ROWS; j++)
			sum += a[i][j];
	return sum;
}

int sum_array_cols(int** a)
{
	int i, j, sum = 0;
	
	for (j = 0; j < ROWS; j++)
		for (i = 0; i < COLS; i++)
			sum += a[i][j];
	return sum;
}

int main()
{
	int** a;
	int i, j, sum = 0;

	a = (int**)malloc(sizeof(int*) * COLS);

	for(i = 0; i < COLS; i++)
		a[i] = (int*)malloc(sizeof(int)*ROWS);
		
	
	for(i = 0; i < COLS; i++)
		for(j = 0; j < ROWS; j++)
			a[i][j] = i;	

#ifdef SUM_COLS		
	sum = sum_array_cols(a);
	printf("sum_cols ... \n");
#endif

#ifdef SUM_ROWS
	printf("sum_rows ... \n");
	sum = sum_array_rows(a);
#endif

	printf("sum = %d\n", sum);

	return 0;
}

