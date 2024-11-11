#include <iostream>
#include <set>
#include <unordered_set>
#include "..\operator_overloading\vector.hpp"

using std::set,  std::unordered_set;
using std::cout, std::endl;

//~ class Vector
//~ {
	//~ public:
		//~ float x, y, z;
		//~ std::string name {""};
//~ };

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
	
	for (int i = 0; i < 10; i++)
	{
		os.insert(i % 5);
		us.insert(i % 5);
	}

	cout << "Set:" << endl;
	print(os);
	cout << "Unordered Set:" << endl;
	print(us);
 
	set <Vector> vs;
	vs.emplace(1.0, 3.0, 2.0);
	vs.emplace(1.0, 2.0, 2.0);
	vs.emplace(1.0, 1.0, 2.0);
	vs.emplace(1.0, 2.0, 2.0);
	cout << "Vector Set:" << endl;
	print(vs);
	
	return 0;
}
