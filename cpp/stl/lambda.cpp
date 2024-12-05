#include <iostream>


int main()
{
	//~ int value = 2;
	
	//~ auto mul = [&value, =](int arg) {return arg * value;};
	//~ value = 0;
	//~ int b = mul(3);
 
	//~ std::cout << mul(3) << std::endl;

	
	int a = 1, b = 2;

	std::cout << "a: " << a << "\tb: "<< b << std::endl;
	auto modify = [a, &b]() { 
	    b = a + b;
	    return b; 
	};
	int result = modify(); // result буде 3, b буде 3
	std::cout << "a: " << a << "\tb: "<< b << std::endl;

	//~ int x = 10;
	//~ auto print = [my_value = x]() { std::cout << my_value << std::endl; };
	//~ x = 20;
	//~ print(); // Виведе 10
 

	return 0;
}
