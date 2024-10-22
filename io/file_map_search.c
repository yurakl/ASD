#include <windows.h>
#include <winbase.h>
#include <fileapi.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//~ Програма пошуку кількості знаходження певного слова в книзі двома способами - звичайне читання файлу та файл відображений у пам'яті
char * file_name = "book.txt";
char * the_word  = "programming";


//~ Функція пошуку у файлі відображеному в пам'яті процесу
void search_via_map()
{
	//~ Лічильник для підрахунку знайдених слів
	unsigned counter = 0;
	clock_t start = clock();
	//~ Створення відображення файлу
	int  * the_file_handle    = CreateFileA(file_name, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	int  * the_mapping_handle = CreateFileMappingA(the_file_handle, NULL, PAGE_READONLY | SEC_COMMIT, 0, 0, NULL);
	
	char * the_mapping        = (char *) MapViewOfFile(the_mapping_handle, FILE_MAP_READ,  0, 0, 0);

	if (the_mapping == NULL)
	{
		perror("Mapping");
		return;
	}
	//~ Позиція старту пошуку - після кожного знайденого слова, позиція переміщаєть за кінець слова
	char  * search_position = the_mapping;
	
	while (search_position = strstr(search_position, the_word))
	{
		counter++;
		search_position += strlen(the_word); 
	}
	printf("file mapping. counter: %d\n", counter);
	clock_t end = clock();
	printf("%lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	UnmapViewOfFile(the_mapping);
	CloseHandle(the_mapping_handle);
	CloseHandle(the_file_handle);
}

//~ Функція пошуку у файлі, який зчитується звичайним способом
void search_via_read()
{
	clock_t start = clock();
	//~ Лічильник для підрахунку знайдених слів
	unsigned counter = 0;

	//~ Відкривання файлу, та створення буфера, в який будемо зчитувати текст
	FILE * the_file  = fopen(file_name, "r");
	int buf_size     = 512;
	char * buffer    = malloc(buf_size);

	//~ Зчитування файлу порціями та пошук слова у кожній порції
	while (fgets(buffer, buf_size, the_file))
	{
		char  * search_position = buffer;
		while (search_position = strstr(search_position, the_word))
		{
			counter++;
			search_position += strlen(the_word);
		}
	}
	printf("file read. counter: %d\n", counter);
	clock_t end = clock();
	printf("%lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}


int main()
{
	search_via_map();
	search_via_read();
	return 0;
}


