#include <iostream>
#include <set>
#include <unordered_set>
#include "box.hpp"

using std::set,  std::unordered_set;
using std::cout, std::endl;


//~ Шаблон функції для друку елементів множини

template <class Type> void print(const Type& container)
{
	for (const auto& el : container)
	{
		cout << el << " ";
	}
	cout << endl;
}


int main()
{
	set <int> os;
	unordered_set <int> us;

	cout << "i % 5: ";
	for (int i = 0; i < 10; i++)
	{
		cout << i % 5 << " ";
		os.insert(i % 5);
		us.insert(i % 5);
	}
	cout << endl;
	cout << "Set:" << endl;
	print(os);
	cout << "Unordered Set:" << endl;
	print(us);


	cout << "Box set: " << endl;
	set <Box> box_set; 
	Box b {1.0, 4.0, 4.0};
	box_set.insert(b);
	box_set.emplace(1.0, 1.0, 1.0);
	box_set.emplace(2.0, 2.0, 1.0);
	box_set.emplace(1.0, 3.0, 1.0);
	box_set.emplace(1.0, 1.0, 1.0);
	print(box_set);
	
	return 0;
}
