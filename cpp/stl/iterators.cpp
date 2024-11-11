#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>

#define LINE {cout << "\n=======================================\n" << endl;}
using std::array, std::vector, std::deque, std::list;
using std::cout, std::endl;


int main ()
{
	
	LINE;
	cout << "        Iterator examples" << endl;
	LINE;

	vector <int> v1;

	v1.reserve(10);
	v1.push_back(55);
	
	//~ vector <int> :: iterator it = v1.begin();

	auto it = v1.begin();
	
	if (it != v1.end())
		cout << "First element: " << *it << endl; 
	else 
		cout << "Empty" << endl;

	LINE
	
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i * i);
	}

	LINE;
	
	for (auto i = v1.begin(); i != v1.end(); i++)
	{
		cout << *i << " ";
	}
	LINE;
	
	vector <int> v2;
	v2.resize(10);
	v2.at(0) = 55;
	cout << v2.at(5) << endl;


	

}
