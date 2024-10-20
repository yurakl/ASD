#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * file_object = fopen("tmp.dat", "w");
	
	setvbuf(file_object, NULL, _IOFBF, BUFSIZ);
	setvbuf(stdout,	   NULL, _IOFBF, BUFSIZ);


	fprintf(file_object, "Hello");
	fprintf(stdout,      "Hello");

	getc(stdin);

	
	_exit(-1); 
	//~ exit(0);
	//~ return 0;
}
