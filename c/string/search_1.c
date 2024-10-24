#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

//~ Програма пошуку слова зі зміною регістру першої літери
                                                                                                                  
int main()
{
	//~ Рядок та слово
	char * string = "One ring to rule them all";
	char * word   = "Ring";

	//~ Друкуємо рядок у консоль
	puts(string);
	//~ Друкуємо довжину рядка та слова
	printf("Length of the string: %d\n", strlen(string)); 
	printf("Length of the word:   %d\n", strlen(word));

	//~ Шукаємо слово в рядку
	char * position = strstr(string, word);

	//~ Якщо не значйдено - змінюємо регістр першої літери
	if (!position) {
		char * _temporary  = strdup(word);
		if(isupper(_temporary[0])) {
			_temporary[0] = tolower(_temporary[0]);
		} else {
			_temporary[0] = toupper(_temporary[0]);
		}
		position = strstr(string, _temporary);
	}

	//~ Друкуємо позицію слова в рядку. Якщо не знайдено, то позиція = -1
	printf("The word  \"%s\" found in \"%s\" at the position %lld", 	word, string, position !=  NULL ? position - string : -1);

}
