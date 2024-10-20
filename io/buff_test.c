#include <stdio.h>
#include <time.h>
#include <fcntl.h>


//~ Прорама тестування швидкості виведення інформації у двох режимах роботи з файлом - з буфером та без.
//~ Кількість записувань у файл
#define NTIME 1000000



int main()
{
	//~ Відкриваємо файл у режимі прямого записування - без буфера
	int  fd = open("tmp.dat", O_CREAT | O_WRONLY);
	char _temporary = 55;
	//~ Засікаємо час та записуємо змінну _temporary NTIME разів
	clock_t start = clock();
	for (int i = 0; i < NTIME; i++)
	{
		write(fd, &_temporary, 1);
	}
	clock_t end = clock();
	//~ Друкуємо час виконання
	printf("Time WITHOUT buffer: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	close(fd);

	//~ Відкриваємо файл в режимі з буфером
	FILE * file_object = fopen("tmp.dat", "w");
	start = clock();
	//~ Засікаємо час та записуємо змінну _temporary NTIME разів
	for (int i = 0; i < NTIME; i++)
	{
		fwrite(&_temporary, 1, 1, file_object);
	}
	end = clock();
	//~ Друкуємо час виконання
	printf("Time WITH buffer:    %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}
