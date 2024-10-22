#include <windows.h>
#include <winbase.h>
#include <fileapi.h>
#include <stdio.h>
#include <string.h>

//~ Файл, який буде завантажено у пам'ять
char * file_name = "book.txt"; 


int main()
{
	//~ Пауза, для перевірки у VMMAP
	getc(stdin);

	//~ Відкривання файлу
	int  * the_file_handle    = CreateFileA(file_name, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//~ Налаштування відображення файлу в пам'яті
	int  * the_mapping_handle = CreateFileMappingA(the_file_handle, NULL, PAGE_READONLY | SEC_COMMIT, 0, 0, NULL);
	//~ Створення відображення файлу в пам'яті процесу
	char * the_mapping        = (char *) MapViewOfFile(the_mapping_handle, FILE_MAP_READ,  0, 0, 0);

	//~ Якщо помилка (вказівник = NULL), то друкуємо її
	if (the_mapping == NULL)
	{
		perror("Mapping");
	}
	printf("%p\n", the_mapping);
	//~ Пауза, для перевірки у VMMAP
	getc(stdin);

	//~ Копіюємо  рядок із файлу відображеного в пам'яті та друкуємо його в консоль
	char str[100];
	memcpy(str, the_mapping, 99); 
	str[100] = '\0';
	puts(str);

	return 0;
}

