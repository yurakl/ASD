#include <iostream>
#include "..\operator_overloading\vector.hpp"


template <typename Type>
Type minima(Type a, Type b)
{
    return a > b ? b : a;
}


template <typename T1, typename T2>
class container
{
    public:
        container() = default;
        container(T1 _a, T2 _b) : a {_a}, b {_b} {};
        T1 a;
        T2 b;
};

int main()
{
    int     a = 3, b = 2;
    float   c = 0.35, d = 1.0;

    Vector  v_1 {1.0, 2.0, 1.0}, v_2 {3.0, 3.0, 3.0};

    cout << "Min int:    " << minima(a, b) << endl;
    cout << "Min float:  " << minima(c, d) << endl;
    cout << "Min Vector: " << minima(v_1, v_2) << endl;

    cout << "\n" << endl;

    container <int, float>  c_1 {a, c};
    container <int, Vector> c_2 {b, v_1};

    cout << "container 1: " << c_1.a << c_1.b << endl;
    cout << "container 2: " << c_2.a << c_2.b << endl;
    
    return 0;
}