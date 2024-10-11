#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#define N  3
                                                                                                                  
int main()
{ 
	int * matrix = calloc(N * N, sizeof(int));
	int i = 1;
	int j = 2;


	int k = i * N + j;

	matrix[k] = 33;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			k = i * N + j;
			printf("%d ", matrix[k]);
		}
		puts("");
	}
	
}
