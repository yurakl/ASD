#include <iostream>
int main()
{
	int	num;
	float var;
	char	str[10];

	std::cout << "Pass a phrase: ";
	std::cin  >> str;

	std::cout << "Pass an interger variable: ";
	std::cin  >> num;

	std::cout << "Pass an float variable: ";
	std::cin  >> var;


	std::cout << "Output" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "num: " << num << std::endl;
	std::cout << "var: " << var << std::endl;

	
}
