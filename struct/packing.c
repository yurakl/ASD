#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <time.h>

//~ Кількість записувань структури у файл
#define NTIME 100000000

//~ Структура без пакування. Та що використана в презентації
struct non_packed_str {
	char	c_var; 
	int   i_var;
	short	s_var;
	long long ll_var;
};
//~ Ручне пакування - розміщення елементів від найбільшого, до найменшого
struct manual_packed_str {
	long long ll_var;
	int   i_var;
	short	s_var;
	char	c_var; 	
};
//~ Пакування з допомогою вказівки компілятору - повне нехтування вирівнювання 
struct packed_str {
	char	c_var; 
	int   i_var;
	short	s_var;
	long long ll_var;
} __attribute__ ((packed));

//~ Головна функція
	
int main()
{
	//~ Файл куди буде проводитись записування
	
	FILE * tmpfile = fopen("tmp.dat", "w+") ;
	//~ Інформація в консоль, зокрема розмір стуктури
	puts("Non packed structure:");
	printf("Size:  %lld\n", sizeof(struct non_packed_str));
	puts("Writing:");

	//~ Оголошуємо об'єкт неупакованої структури
	struct non_packed_str obj_1;
	//~ Засікаємо час
	clock_t start = clock();
	//~ Цикл із записуванням у файл
	for (int i = 0; i < NTIME; i++)
	{
		fwrite(&obj_1, sizeof(obj_1), 1, tmpfile);
	};
	//~ Зупиняємо таймер
	clock_t end = clock();
	//~ Друкуємо час у консоль
	printf("Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	//~ Закриємо файл та відкриємо знову, щоб очистити його
	fclose(tmpfile);
	//~ Опція w+  відкриває файл для читання та додатково очищує файл
	tmpfile = fopen("tmp.dat", "w+") ;

	
	//~ Інформація в консоль, зокрема розмір стуктури
	puts("=====================================");
	puts("Manualy packed structure:");
	printf("Size:  %lld\n", sizeof(struct manual_packed_str));
	puts("Writing:");
	//~ Об'єкт  упакованої вручну структури
	struct manual_packed_str obj_2;
	//~ Засікаємо час
	start = clock();
	//~ Цикл із записуванням у файл
	for (int i = 0; i < NTIME; i++)
	{
		fwrite(&obj_2, sizeof(obj_2), 1, tmpfile);
		
	};
	//~ Зупиняємо таймер
	end = clock();
	//~ Друкуємо час у консоль
	printf("Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	//~ Закриємо файл та відкриємо знову, щоб очистити його
	fclose(tmpfile);

	tmpfile = fopen("tmp.dat", "w+") ;


	//~ Інформація в консоль, зокрема розмір стуктури
	puts("=====================================");
	puts("Packed structure:");
	printf("Size:  %lld\n", sizeof(struct packed_str));
	puts("Writing:");

	//~ Об'єкт упакованої примусово структури
	struct packed_str obj_3;
	//~ Засікаємо час
	start = clock();
	//~ Цикл із записуванням у файл
	for (int i = 0; i < NTIME; i++)
	{
		fwrite(&obj_3, sizeof(obj_3), 1, tmpfile);
	};
	//~ Зупиняємо таймер
	end = clock();
	//~ Друкуємо час у консоль
	printf("Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	 
}
