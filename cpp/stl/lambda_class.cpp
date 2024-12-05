#include <iostream>

class LambdaClass {
private:
	int x;       // Захоплена змінна за значенням
	int& y;      // Захоплена змінна за посиланням

public:
	// Конструктор для ініціалізації захоплених змінних
	LambdaClass(int capturedX, int& capturedY) : x(capturedX), y(capturedY) {}

	// Перевантажений оператор виклику
	int operator()(int a, int b) const { return a * x+ b * y; }
};

int main()
{
	int x = 2;
	int y = 3;

	// Створення еквівалентного об'єкта класу
	LambdaClass lambda(x, y);

	// Виклик об'єкта
	std::cout << lambda(1, 2) << std::endl;  

	// Зміна b вплине на результат, оскільки b захоплене за посиланням
	y = 5;
	std::cout << lambda(1, 2) << std::endl; // Виведе 45

    return 0;
}
