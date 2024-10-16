#include <stdio.h> 

//~ Програма налаштування буферизації

int main()
{
	//~ Відкриваємо файл
	FILE * file_object = fopen("tmp.dat", "w");

	//~ Вимкнення буферизації для файлу
	setvbuf(file_object, NULL, _IONBF, BUFSIZ);
	//~ Лінійна буферизація для стандартного потоку виводу
	setvbuf(stdout,	   NULL, _IOFBF, BUFSIZ);

	//~ Друк першої фрази
	fprintf(file_object, "First output");
	fprintf(stdout,      "First output");

	//~ Пауза доки не натиснеться Enter
	getc(stdin);

	//~ Друк першої фрази
	fprintf(file_object, "...Second output\n");
	fprintf(stdout,      "...Second output\n");

	//~ Пауза доки не натиснеться Enter
	getc(stdin);
}

