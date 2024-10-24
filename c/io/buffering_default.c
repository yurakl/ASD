#include <stdio.h> 

//~ Програма для перевірки стандартної буферизації

int main()
{ 
	//~ Відкриваємо файл
	FILE * file_object = fopen("tmp.dat", "w");

	//~ Друк першої фрази (без перенесення на новий рядок) в файл та консоль
	fprintf(file_object, "First output");
	fprintf(stdout,      "First output");

	//~ Пауза доки не натиснеться Enter
	getc(stdin);

	//~ Друк наступної фрази з перенесенням на новий рядок в файл та консоль
	fprintf(file_object, "...Second output\n");
	fprintf(stdout,      "...Second output\n");

	//~ Пауза доки не натиснеться Enter
	getc(stdin);
}
