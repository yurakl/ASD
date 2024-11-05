#include "vector.hpp"

int main()
{
    Vector v_1{2.0, 3.0, 4.0}, v_2 ;
    string v_name = "force";
    
    v_1 =  v_1 + v_name;
    cout << v_1;

    return 0;
}
