#include <iostream>
#include <map>
#include <unordered_map>
#include "..\operator_overloading\vector.hpp"

using std::map,  std::unordered_map;
using std::cout, std::endl;

//~ class Vector
//~ {
	//~ public:
		//~ float x, y, z;
		//~ std::string name {""};
//~ };

template <class Type_1, class Type_2> void print(const map<Type_1, Type_2>  container)
{
	for (const auto& el : container)
	{
		cout << el.first << " " << el.second;
	}
}


int main()
{
	map <std::string, Vector> om;

	om["force"] = {1.0, 1.0, 2.0}; 
	om["velocity"] = {1.0, 2.0, 2.0};

	
	//~ Vector  v{0.0, і0.0, 0.0};
	//~ om.insert({"force", v});

	
	print(om);
	return 0;
}
