#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main() {

	//~ std::cout << "Regular array" << std::endl;
	//~ int arr[] = {1, 2, 3, 4, 5};
	//~ int* ptr = arr;

	//~ for (size_t i = 0; i < 5; ++i)
	//~ {
		//~ std::cout << "Value: " << *(ptr + i) << ", Address: " << (ptr + i) << std::endl;
	//~ }
 
	//~ std::cout << "Vector" << std::endl;
	//~ std::vector<int> vec = {1, 2, 3, 4, 5};
    
	//~ for (auto it = vec.begin(); it != vec.end(); ++it)
	//~ {
		//~ std::cout << "Value: " << *it << ", Address: " << &(*it) << std::endl;
	//~ }
	
	//~ std::cout << "Deque" << std::endl;
	//~ std::deque<int> dq;
	//~ dq.reserve(1000);
	//~ dq.resize(10);
	//~ auto it_0 = dq.begin();
	//~ for (auto it = dq.begin() + 1; it != dq.end(); ++it)
	//~ {
		//~ std::cout << "Value: " << *it << ", Address: " << &(*it) - &(*it_0) << std::endl;
	//~ }

	//~ std::cout << "List" << std::endl;
	//~ std::list<int> lst;
	//~ lst.resize(10);
	//~ for (auto it = lst.begin(); it != lst.end(); ++it)
	//~ {
		//~ std::cout << "Value: " << *it << ", Address: " << &(*it)  << std::endl;
	//~ }
	
	return 0;
}
