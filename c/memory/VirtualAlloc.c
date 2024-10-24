#include <stdio.h> 
#include <memoryapi.h>

//~ Макрос розміру сторінки пам'яті
#define PAGE 4096

//~ Програма для виділення пам'яті процесу в операційній системі Windows
int main()
{
	//~ Вказівник, якому буде присвоєна адреса початку виділеної області пам'яті
	int * ptr = NULL;
	//~ Виділення сторінки пам'яті
	ptr = (int *) VirtualAlloc(NULL, PAGE,
						MEM_COMMIT	| MEM_RESERVE, 
						PAGE_READWRITE);
	//~ Друк вказівника
	printf("Memory starts at: %p\n", ptr);

	//~ Заповнення виділеної пам'яті змінними типу int
	for (int i = 0; i < PAGE / sizeof(int); i++)
	{
		ptr[i] = i;
	}

	//~ Друк для перевірки аварійного завершення роботи програми
	puts("Success");

}
