#include <stdio.h>
#include <sys/mman.h>

#define PAGE 4096

//~ Програма для виділення пам'яті процесу в POSIX-системах (Linux, Unix, Mac) 
int main(void)
{
	
	//~ Вказівник, якому буде присвоєна адреса початку виділеної області пам'яті
	int * ptr = NULL;
	//~ Виділення сторінки пам'яті
	ptr = mmap(NULL, PAGE, PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	//~ Друк вказівника
	printf("Memory starts at: %p\n", ptr);

	//~ Заповнення виділеної пам'яті змінними типу int
	for (int i = 0; i < PAGE / sizeof(int); i++)
	{
		ptr[i] = i;
	}

	//~ Друк для перевірки аварійного завершення роботи програми
	puts("Success");
	
	return 0;
}
