#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;
void * operator new(size_t size)
{
	cout << "New" << endl;
	void * ptr = malloc(size);
	return ptr;
}

int main()
{
	vector<int> v1;
	v1.reserve(10); 

	fill(v1.begin(), v1.end(), 33);

	list<int> l1;
	l1.resize(5);

	//~ copy(v1.begin(), v1.begin() + 5, l1.begin());
	transform(v1.begin(), v1.begin() + 5, l1.begin(), [](int a){return a * a;});
	
	//~ cout << "list" << endl;
	
	//~ for(const auto& el : l1)
	//~ {
		//~ cout << el << "; ";
	//~ }
	//~ cout << endl; 
	return 0;
}
