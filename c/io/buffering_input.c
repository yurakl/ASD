#include <stdio.h>
#include <stdlib.h>


//~ Програма перевірки вхідного буфера
int main()
{
	//~ Відкриваємо файл та записуємо туди послідовність байтів: 512 байтів - 'A', наступні 512 байтів - 'B'
	FILE * file_object = fopen("tmp.dat", "w");
	for (int i = 0; i < 512; i++)
	{
		fprintf(file_object, "%c", 'A');
	}
	for (int i = 0; i < 512; i++)
	{
		fprintf(file_object, "%c", 'B');
	}

	//~ for (int i = 0; i < 512; i++)
	//~ {
		//~ fprintf(file_object, "%c", 'C');
	//~ }
	//~ for (int i = 0; i < 512; i++)
	
	//~ {
		//~ fprintf(file_object, "%c", 'D');
	//~ }
	fclose(file_object);

	//~ Закриваємо файл та відкриваємо тепер для читання
	
	file_object = fopen("tmp.dat", "r");

	//~ Створюємо буфер, який призначимо як вхідний для цього файлу
	char * my_buff = malloc(512);
	printf("Buffer size: %d\n", 512);

	//~ Тимчасова змінна, в неї будемо зчитувати з файлу
	char _temporary;

	//~ Встановлюємо буфер для файлу
	setvbuf(file_object, my_buff, _IOFBF, 512);

	//~ Яитаємо з файлу та друкуємо інформацію
	fread(&_temporary, 1, 1, file_object);

	//~ Після зчитування друкуємо початок та кінець буферу
	puts("\nBuffer after 1-byte read:");
	printf("\t0:     %c\n", my_buff[0]);
	printf("\t511:   %c\n", my_buff[511]); 

	for (int i = 0; i < 511; i++)
	{
		fread(&_temporary, 1, 1, file_object);
	}
	puts("\nBuffer after 1 + 511-byte read:");
	printf("\t0:     %c\n", my_buff[0]);
	printf("\t511:   %c\n", my_buff[511]); 

	
	fread(&_temporary, 1, 1, file_object);

	puts("\nBuffer after 1 + 511 + 1-byte read:");
	printf("\t0:     %c\n", my_buff[0]);
	printf("\t511:   %c\n", my_buff[511]);

	fseek(file_object, 0, SEEK_SET);
	fread(&_temporary, 1, 1, file_object);
	puts("\nBuffer after return and 1-byte read:");
	printf("\t0:     %c\n", my_buff[0]);
	printf("\t511:   %c\n", my_buff[511]);
	
}
