#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
                                                                                                                  
int main()
{

	//~ Пошук слова в рядку. Випадок, коли слово зустрічається декілька разів
	char * string = "One ring to rule them all, one Ring to find them, One Ring to bring them all, and in the darkness bind them; In the Land of Mordor where the shadows lie.";
	char * word   = "ring";

 
	puts(string);
	printf("Length of the string: %d\n", strlen(string)); 
	printf("Length of the word:   %d\n", strlen(word));

	//~ створюємо два дублікати слова - за ними буде пошук
	//~ Це масив вказівників на рядки
	char * _temporary[2];
	_temporary[0] = strdup(word);
	_temporary[1] = strdup(word);

	//~ В одному дублікаті (другому) змінюємо регістр першої літери (нульового елементу) 
	if(isupper(_temporary[1][0])) {
		_temporary[1][0] = tolower(_temporary[1][0]);
	} else {
		_temporary[1][0] = toupper(_temporary[1][0]);
	}

	//~ Позиція з якої починається пошук
	char * search_position = string;
	//~ Позиція слова
	char * word_position[2];
	//~ Тимчасовий вказівник - йому присвоюємо найменшу позицію (і НЕНУЛЬОВУ).
	char *_wp;
	
	do {
		//~ робимо першу спробу, якщо вдала - далі цикл
		word_position[0] = strstr(search_position, _temporary[0]);
		word_position[1] = strstr(search_position, _temporary[1]);


		//~ Нам потрібно обрати менший НЕНУЛЬОВИЙ вказівник

		//~ Спочатку присвоюємо перший вказівник, якщо він не NULL, якщо NULL то другий
		_wp = word_position[0] != NULL ? word_position[0] : word_position[1];
		//~ Перевіряємо другий на NULL, якщо NULL то залишаємо так як є (_wp = word_position[0])  - два вказівники = NULL, або _wp = word_position[0], якщо він(word_position[0]) не NULL 
		//~ Якщо другий не NULL, тоді перевіряємо, чи він менший зазначення у _wp (там одни із ненульових або [0] або [1])
		//~ Якщо word_position[1] < _wp, то _wp = word_position[1], якщо не менший - залишаємо старе значення
		_wp = (word_position[1] != NULL && word_position[1] < _wp)  ? word_position[1] : _wp;
		 
 
		
		//~ Зміщуємо позицію пошуку за знайдене слово
		search_position = _wp + strlen(word);
		//~ Друкуємо позицію слова в рядку 
		printf("The word  \"%s\" found  at the position %lld\n", word,  _wp !=  NULL ? _wp - string : -1);
	}
	while(_wp);
	puts("End");
}
