#include <iostream>
using namespace std;

//~ Приклад перевантаження функцій - функції мають однакове значення, але різні аргументи

void function(int a)
{
	cout << "function(int a)" << endl;
}
void function(int a, int b)
{
	cout << "function(int a, int b)" << endl;
}
void function(int a, short b)
{
	cout << "function(int a, short b)" << endl;
}


int main()
{
	function(1);
	function(1, 2); 
	function(1, (short) 2); 
	return 0;
}
