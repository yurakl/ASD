#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main()
{

	
	char str_1[] = "Hello";

	char * str_2 = "Hello";

	char * str_3 = malloc(10);

	printf("Location of STR_1:  %p\n", str_1);
	printf("Location of STR_2:  %p\n", str_2);
	printf("Location of STR_3:  %p\n", str_3); 
	getc(stdin);
	
}
