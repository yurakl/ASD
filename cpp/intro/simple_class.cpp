#include <iostream>

//~ Приклад простого класу - клас Box, містить три значення int - сторони коробки

class Box
{
	//~ Доступні ззовні поля
	public:
		//~ Функції для отримання значення сторін
		int get_a() {return a;};
		int get_b() {return b;};
		int get_c() {return c;};
		//~ Функція для встановлення значення сторін. Тут тільки прототип
		void set_abc(int length, int width, int height);

	private:
		//~ int a , b, c;
		//~ Варіан опису із зазначенням значення за замовчуванням
		int a {3}, b {3}, c {3};
};

//~ Визначення функції для встановлення значень сторін
void Box::set_abc(int length, int width, int height)
{
	//~ Додатково перевіряємо, чи значення менше за 1, якщо менше - тоді сторона = 1
	a = length < 1 ? 1 : length;
	b = width  < 1 ? 1 : width;
	c = height < 1 ? 1 : height;
}

int main()
{
	//~ Створення трьох об'єктів класу Box
	Box obj_1, obj_2, obj_3;

	//~ Встановлення значень сторін кожного об'єкту через виклик функції
	obj_1.set_abc(2, 3, 4);
	 
	obj_3.set_abc(0, 0, 2); 

	//~ Виведення значень сторін, через виклик функцій 
	std::cout << "Available boxes:\n";
	std::cout << "\t" << obj_1.get_a() << "x" << obj_1.get_b() << "x" << obj_1.get_c() << std::endl;
	std::cout << "\t" << obj_2.get_a() << "x" << obj_2.get_b() << "x" << obj_2.get_c() << std::endl;
	std::cout << "\t" << obj_3.get_a() << "x" << obj_3.get_b() << "x" << obj_3.get_c() << std::endl;

}
