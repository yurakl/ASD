#include <Windows.h> 

int main()
{
	//~ Рядок, який необхідно вивести
	char str[14] = "Hello, World\n";

	//~ Відкриваємо файл, отримуємо вказівник на номер файлу
	int  * OutFile = CreateFileA("tmp.dat", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//~ Записуємо у файл
	WriteFile(OutFile, str, 14, NULL, NULL); 
	
	//~ Функція для отримання вказівника на номер стандартного потоку виведення
	int * Out = GetStdHandle(STD_OUTPUT_HANDLE);
	//~ Записуємо у стандартний потік виведення - у консоль
	WriteFile(Out, str, 14, NULL, NULL);
	
}
