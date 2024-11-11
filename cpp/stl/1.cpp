#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>



#define SIZE 10
#define LINE {cout << "=======================================" << endl;}
using std::array, std::vector, std::deque, std::list;
using std::cout, std::endl;

 


int main()
{

	//~ using int_10 = array <int, 10>;

	//~ int_10 i_array_1;

	
	array   <int,  SIZE> i_array;
	vector  <int> i_vector;
	deque   <int> i_deque;
	list    <int> i_list;

	//~ i_array.at(5)  = 22;	// ok
	//~ i_vector.at(5) = 22;	// not ok
	
	i_vector.reserve(10);
	
	//~ cout << "i_vector is:       " << (i_vector.empty() ? "empty" : "not empty") << endl;
	cout << "i_vector size:     " << i_vector.size()     << endl;
	cout << "i_vector capacity: " << i_vector.capacity() << endl;

	
	for (int i = 0; i < SIZE; i++)
	{
		i_array.at(i) = i * i;
		i_vector.push_back(i * i);
	}
	LINE
	//~ cout << "i_vector is:       " << (i_vector.empty() ? "empty" : "not empty") << endl;
	cout << "i_vector size:     " << i_vector.size()     << endl;
	cout << "i_vector capacity: " << i_vector.capacity() << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << i_array.at(i) << " ";
		cout << i_vector[i]   << endl;
	}

	i_vector.front() = 33;
	i_vector.at(1) = 44;
	cout << "i_vector[0]: " << i_vector.at(0) << endl; 
	cout << "i_vector[0]: " << i_vector.at(1) << endl;

	
	
	return 0;
}

