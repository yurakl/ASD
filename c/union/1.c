#include <stdio.h> 
#include <stdint.h>


//~ Цілочисельні константи для розрізнення типів у контейнері
enum type {i_t, f_t};

//~ Визначення контейнера із анонімим об'єднанням 
typedef struct {
		enum type t;
		union {
			int	i_var[2];
			float f_var[2];
		};
	} container;

//~ Функція, що отримує контейнер 
void product(container c)
{
	//~ Розгалуження в залежності від типу
	switch(c.t)
	{
		case(i_t):
			printf("Integer product: %d\n", c.i_var[0] * c.i_var[1]);
			break;
		case(f_t):
			printf("Float product:   %f\n", c.f_var[0] * c.f_var[1]);
			break;
		default:
			puts("Unknown type");
			break;
	}
}

int main()
{
	//~ Оголошення двох об'єктів контейнера
	container array[2]; 

	//~ Перший буде із змінними типу int
	array[0].t = i_t;
	array[0].i_var[0] = 3;
	array[0].i_var[1] = 4;
	//~ Другий - із float
	array[1].t = f_t;
	array[1].f_var[0] = 3.14;
	array[1].f_var[1] = 4.4;

	product(array[0]);
	product(array[1]);
}
