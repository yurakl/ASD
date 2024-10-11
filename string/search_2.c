#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
                                                                                                                  
int main()
{

	//~ Пошук слова в рядку. Випадок, коли слово зустрічається декілька разів
	char * string = "One ring to rule them all, one ring to find them, One ring to bring them all, and in the darkness bind them; In the Land of Mordor where the shadows lie.";
	char * word   = "ring";

 
	puts(string);
	printf("Length of the string: %d\n", strlen(string)); 
	printf("Length of the word:   %d\n", strlen(word));

	//~ Позиція з якої починається пошук
	char * search_position = string;
	//~ Позиція слова
	char * word_position;
	do {
		//~ робимо першу спробу, якщо вдала - далі цикл
		word_position = strstr(search_position, word);
		//~ Зміщуємо позицію пошуку за знайдене слово
		search_position = word_position + strlen(word);
		//~ Друкуємо позицію слова в рядку 
		printf("The word  \"%s\" found  at the position %lld\n", word,  word_position !=  NULL ? word_position - string : -1);
	}
	while(word_position);
	puts("End");
}
