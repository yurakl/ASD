#include <iostream>


//~ Бібліотека, що містить визхначення класу Vector та переваньтажені оператори для нього
using std::cout, std::endl, std::string;

//~ Визначення класу
class Vector
{
	//~ Приватні поля класу - значення координат та ім'я вектора
	private:
	
		float x {1.0}, y {1.0}, z {1.0};
		string name {"Unknown"};

	//~ Поля, що доступнні ззовні
	public:

		//~ Статична змінна - один екземпляр для всіх класів.
		//~ Тут це лічильник створених об'єктів класу
		static inline int counter;

		//~ Методи для отримання координат щ об'єкту 
		float get_x() const {return x;};
		float get_y() const {return y;};
		float get_z() const {return z;};

		//~ Статична функція - може викликатись і без створеного об'єкту - Vector::max_vector();
		//~ Тут це просте друкування повідомдення
		void static max_vector(){
			cout << "Max values are not defined - up to infinity" << endl;
		}

	//~ Конструктор класу за замовчуванням - без аргументів
	Vector() {counter++;};
	//~ Конструктор з аргументами
	Vector(float _x, float _y, float _z) : x{_x}, y {_y}, z {_z} {counter++;};

	//~ Конструктор копіювання - виконується при створені копії об'єкту - присвоєнні значення об'єкту іншому
	Vector(const Vector& origin);

	//~ Перевантажений оператор виведення
	friend std::ostream& operator << (std::ostream& stream, const Vector& v);

	//~ Оператор додавання двох векторів
	friend Vector 	operator + (const Vector& v_1, const Vector&   v_2);
	//~ Оператор додавання до вектора величини float
	friend Vector 	operator + (const Vector& v_1, const float     var);
	//~ Те саме, тільки зі зміненим порядком доданків
	friend Vector 	operator + (const float   var, const Vector&   v_1);

	//~ Оператор зміни (додавання) ім'я ветору
	friend Vector& 	operator + (Vector& v_1, const string   _name);
	//friend float&  operator[](int i);

	//~ Оператор для порівняння векторів
	friend int 		operator > (const Vector& v_1, const Vector& v_2);
};

//~ Конструктор копіювання - просто присвоюємо новому об'єкту значення полів об'єкту, до якого прирівнюємо
Vector::Vector(const Vector& origin) : x {origin.x}, y {origin.y}, z {origin.z}, name {origin.name + " duplicate"}
{
	//~ Друкування повідомлення про використання конструктора копіювання
	cout << "Copy constructor is applied" << endl;
	//~ Збільшення лічильника, оскільки створюється новий об'єкт
	counter++;
}

//~ Оператор додавання двох векторів:
		//~ v_1 + v_2
//~ Результатом є якийсь інший вектор.
//~ v_1 та v_2 не змінюються.
//~ Тому, при представлені у вигляді функції, робимо наступне:
//~ Створюємо об'єкт, який є результатом додавання, та повертаємо його за значенням із функції

Vector operator + (const Vector& v_1, const Vector& v_2)
{
	Vector v_3 {v_1.x + v_2.x, v_1.y + v_2.y, v_1.z + v_2.z};
	v_3.name = v_1.name + " + " + v_2.name;
	return v_3;
}

//~ Додавання числа до об'єкту
//~ Те ж саме, що при додаванні двох об'єктів - створюємо інший об'єкт, який є результатом додавання, та повертаємо його із операції.
Vector operator + (const Vector& v_1, const float var)
{
	Vector v_3 {v_1.x + var, v_1.y + var, v_1.z + var};
	return v_3;
}
//~ Операція із іншим порядком доданків
Vector operator + (const float var, const Vector& v_1)
{
	Vector v_3 {v_1.x + var, v_1.y + var, v_1.z + var};
	return v_3;
}

//~ Перевантаження оператора виведення.
//~ Перший аргумент - це об'єкт класу стандартного потоку виведення - його необ'хідно змінити:
//~ Подібно до звичайного виведення ми по черзі додаємо (<<) до цього класу поля, які необ'хідно видрукувати
//~ Після того, повертаємо посилання на цей об'єкт виведення
std::ostream& operator << (std::ostream& stream, const Vector& v)
{
	stream << v.name << ": " << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << endl;
	return stream;
}

//~ Оператор порівняння - чи аргумент 1 більший за аргумент 2
int operator > (const Vector& v_1, const Vector& v_2)
{
	if ((v_1.x * v_1.x + v_1.y * v_1.y + v_1.z * v_1.z) > (v_2.x * v_2.x + v_2.y * v_2.y + v_2.z * v_2.z)) {
		return 1;
	} else {
		return 0;
	}
}

//~ Оператор додавання вектора та рядка - рядок доається до імені вектора
Vector& operator + (Vector& v_1, string _name)
{
	if (v_1.name == "Unknown") {
		v_1.name = _name;
	} else {
		v_1.name = v_1.name + " " + _name;
	}
	return v_1;	
}
