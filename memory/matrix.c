#include <stdio.h>
#include <stdlib.h> 

//~ Приклад динамічного виділення пам'яті для матриці

//~ Рощмір матриці
#define N 3                                                       
                                                                       
int main()
{

	//~ Створення масиву вказівників - вказівників на рядки матриці
	int ** ptr = (int **) malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++)
	{
		//~ Створення масиву int - рядок матриці
		ptr[i] = (int*) malloc(N * sizeof(int));
	}

	//~ Заповнення матриці значеннями
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ptr[i][j] = i * j;
		}
	}

	//~ Друк матриці в консоль
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d  ", ptr[i][j]);
		}
		puts("");
	} 

	
	
}
