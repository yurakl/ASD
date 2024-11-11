#include <iostream> 
#include <vector>
#include "..\operator_overloading\vector.hpp"

#define LINE {cout << "\n=======================================\n" << endl;}
using std::vector;
using std::cout, std::endl;

#define N 3

int main()
{
	using Vector_Container =  vector <Vector>; 
	Vector_Container vc;
    
	vc.reserve(3);

	//~ for (int i = 0; i < 3; i++)
	//~ {
		//~ Vector v{static_cast<float> (i), static_cast<float> (i), static_cast<float> (i)};
		//~ vc.push_back(v); 
	//~ }
	//~ vc.resize(3);
	//~ for (auto it = vc.begin(); it != vc.end(); it++)
	//~ {
		//~ vc.emplace(it, 1.0, 1.0, 1.0);
	//~ }
 
	for (int i = 0; i < 3; i++)
	{
		vc.emplace_back(1.0, 1.0, 1.0); 
	}
	 
}
