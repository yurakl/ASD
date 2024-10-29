#include <iostream>
#include <string>

//~ Приклад основних операцій із контейнером string

int main()
{
	//~ Оголошення та ініціалізація
	std::string str_1 = "Hello";
	std::string str_2 = "World";

	//~ Друкування кожного символу - доступ до елементів рядка
	for (int i = 0; i < str_1.size(); i++)
	{
		std::cout << str_1[i] << std::endl;
	}

	//~ Порівняння рядків
	if (str_1 == str_2) {
		std::cout << "Strings are equal" << std::endl;
	} else {
		std::cout << "Strings are NOT equal" << std::endl;
	}

	//~ Додавання рядків
	str_1 = str_1 + ", " + str_2;

	std::cout << "str_1 + \", \" + str_2:\t"  << str_1 << std::endl;

	//~ Друк рядка та зчитування з консолі
	std::cout << "Pass your name:\t" << std::endl;
	std::cin  >> str_2;
	std::cout << "Hello, " << str_2;
	
	return 0;
}

