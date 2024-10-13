#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//~ Визначення структури та створення її об'єкта
struct my_struct {
	int a;
	short b;
	char c;
	} obj = {
	.a = 0x11111111,
	.b = 0x2222,
	.c = 0x33,
	};
//~ Рядок, що буде записаний у файл
char * str = "Hello, World";
//~ Масив, що буде записаний у файл
int array[3] = {0x55555555, 0x66666666, 0x77777777};
                                                                                                                  
int main()
{
	//~ Ім'я файлу
	char * file_name   = "tmp.dat"; 
	//~ Відкриття файлу для записування
	FILE * file_object = fopen(file_name, "w");

	//~ Записування структури, рядка та масиву у файл в неформатованому вигляді
	fwrite(&obj, sizeof(struct my_struct), 1, file_object);
	fwrite(str, sizeof(char), strlen(str) + 1, file_object); 
	fwrite(array, sizeof(int), 3, file_object);

	//~ Закривання файлу
	fclose(file_object);

	//~ Відкриваємо файл знову, але тепер для читання
	file_object = fopen(file_name, "r");

	//~ Оголошуємо об'єкти, в які запишемо зчитані з фалу структуру, рядок, та масив
	struct my_struct obj_from_file; 
	char str_from_file[strlen(str) + 1];
	int array_from_file[3];
	
	//~ Читаєемо з файлу структуру, рядок та масив
	fread(&obj_from_file, sizeof(struct my_struct), 1, file_object);
	fread(str_from_file, sizeof(char), strlen(str) + 1, file_object); 
	fread(array_from_file, sizeof(int), 3, file_object);

	//~ Друк в консоль зчитаних даних
	printf("struct from file:\n");
	printf("\t.a = %x\n", obj_from_file.a);
	printf("\t.b = %hx\n", obj_from_file.b);
	printf("\t.c = %x\n", obj_from_file.c);
	
	printf("str from file:\n");
	printf("\t%s\n", str_from_file);
	
	printf("array from file:\n");
	printf("\t%x %x %x\n", array_from_file[0], array_from_file[1], array_from_file[2]);
}
