#include <iostream>

//~ Приклад простого класу - клас Box, містить три значення int - сторони коробки
//~ Цей клас містить різні варіанти конструктора - функція, що виконуються при створенні класу

class Box
{
	public:
		//~ Варіанти конструктора
		//~ По замовчуванню - без аргументів
		Box();
		//~ Той, що приймає три аргументи. Створення об'єкту: Box obj {2, 1, 1};
		Box(int length, int width, int height);
		//~ Варіант, коли необхідно створити куб - один аргумент, оскільки всі сторони рівні
		Box(int side);

		//~ Деструктор. Може бути тільки одни. Функція, що виконується при видаленні об'єкту
		~Box();
		
		int get_a() {return a;};
		int get_b() {return b;};
		int get_c() {return c;};
		
		void set_abc(int length, int width, int height);

	private: 
		int a {3}, b {3}, c {3};
		//~ p - периметр. Додано для перевірки порядку ініціалізації - оскільки в класі всін оголошений останнім, то проініціалізований буде теж останнім
		int p {0};
};
//~ Конструктор по замовчуванню. Додамємо просте виведення повідомлення
Box::Box()
{
	std::cout << "Default constructor is applied" << std::endl;
}

//~ Деструктор
Box::~Box()
{
	std::cout << "Deleting the object" << std::endl;
}

//~ Коструктор з аргументами
Box::Box(int length, int width, int height) : p {a + b + c}, a {length}, b {width}, c {height}
{
	std::cout << "Overloaded constructor is applied" << std::endl;
	std::cout << "p = " << p << std::endl;
}
//~ Конструктор з одним аргументом викликає інший, той що з трьома аргументами

Box::Box(int side) : Box(side, side, side)
{
	std::cout << "Overloaded constructor for CUBE is applied" << std::endl;
}

void Box::set_abc(int length, int width, int height)
{
	a = length < 1 ? 1 : length;
	b = width  < 1 ? 1 : width;
	c = height < 1 ? 1 : height;
}


int main()
{
	//~ Box obj_1, obj_2 {}, obj_3 {2, 4, 6};
	//~ Box obj_4 {2, 1, 1};
	Box obj_4 {2};
 

	std::cout << "Available boxes:\n";
	//~ std::cout << "\t" << obj_1.get_a() << "x" << obj_1.get_b() << "x" << obj_1.get_c() << std::endl;
	//~ std::cout << "\t" << obj_2.get_a() << "x" << obj_2.get_b() << "x" << obj_2.get_c() << std::endl;
	//~ std::cout << "\t" << obj_3.get_a() << "x" << obj_3.get_b() << "x" << obj_3.get_c() << std::endl;
	std::cout << "\t" << obj_4.get_a() << "x" << obj_4.get_b() << "x" << obj_4.get_c() << std::endl;

}
