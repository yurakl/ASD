#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using si = pair <string, int>;

int main()
{
	map <string, int> mp;
	mp["a"] = 22; 
	mp["b"] = 32; 
	mp["c"] = 4; 
	mp["d"] = 18; 
	mp["e"] = 100;

	cout << "Map: " << endl;
	for (auto&  [key, value] : mp)
	{
		cout << key << " - " << value << endl;
	}
	
	vector <si> v;
	copy(mp.begin(), mp.end(), back_inserter(v));
	sort(v.begin(),  v.end(), [](const si& a, const si& b) { return a.second < b.second;});   
	
	cout << "Vector: " << endl;
	for (auto&  [key, value] : v)
	{
		cout << key << " - " << value << endl;
	}

	
}
