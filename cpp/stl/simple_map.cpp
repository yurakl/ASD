#include <iostream>
#include <map>
#include <unordered_map>
#include "box.hpp"

using std::map,  std::unordered_map;
using std::cout, std::endl;

//~ Функція друку елементів словника 
template <class Type_1, class Type_2> void print(const map<Type_1, Type_2>  container)
{
	for (const auto& el : container)
	{
		cout << el.first << " " << el.second << "; ";
	}
	cout << endl;
}


int main()
{
	//~ Словник із вбудованими типами - пара рядок-число
	map <std::string, int> simple_map;

	//~ Варіанти додавання елементів
	simple_map["one"] = 1;
	simple_map.insert({"two", 2});
	simple_map.emplace("three", 3);

	//~ Друк словника
	cout << "Simple Map: ";
	print(simple_map);
	cout << endl;

	//~ Словник із власним типом даних - пара рядок-коробка
	map <std::string, Box> om;

	//~ Додавання пар
	om["candies"] = {1.0, 1.0, 2.0}; 
	om["cookies"] = {1.0, 2.0, 2.0};
	om["cookies"] = {2.0, 2.0, 2.0};
	om["fruits"] =  {1.0, 1.0, 2.0};

	
	//~ Створення коробки, та присвоєння їй значення тої, що із ключем fruits
	Box b = om["fruits"];

	cout << "Box with fruits: " << b << endl;

	Ще варіант додавання елементу.
	
	Box potato_box {3.0, 3.0, 3.0};
	om.insert({"potatoes", potato_box});

	//~ Виклик функції друку словника
	print(om);
		
	return 0;
}
