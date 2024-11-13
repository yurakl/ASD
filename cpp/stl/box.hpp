#include <iostream> 
using std::cout, std::endl;

//~ Клас Box для прикладів із множиною та сдловником
class Box
{
	public:
		//~ Розміри коробки
		float x, y, z;
		//~ Конструктор за замовчуванням
		Box() = default;
		//~ Конструктор із аргументами - для сворення на місці в контецнері
		Box(float _x, float _y, float _z) : x {_x}, y {_y}, z {_z} {};
		//~ Оператор порівняння
		friend bool operator < (const Box& first, const Box& second);
		//~ Оператор виведення
		friend std::ostream&  operator << (std::ostream& stream, const Box& box);
};

//~ Визначення оператора порівняння:
	//~ якщо об'єм першого аргументу більший - повертаємо 1, якщо ні - 0.
bool operator < (const Box& first, const Box& second)
{
	if ((first.x * first.y * first.z) < (second.x * second.y * second.z)) {
		return true;
	} else {
		return false;
	}
};

//~ Визначення оператора виведення для Box - друк сторін коробки
std::ostream&  operator << (std::ostream& stream, const Box& box){
	stream << box.x << "*" << box.y << "*" << box.z;
	return stream;
}

