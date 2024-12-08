#include <iostream>

class Base
{
    public:
        int a {-1};
        Base(int arg) : a {arg} {};
};

class Derived : public Base
{
    public:
        int b {-1}; 
        using Base::Base;
        Derived(int arg_1, int arg_2) : Base {arg_1}, b {arg_2} {};
};


int main() {
     
    Derived d_1 {1, 2};
    std::cout << "d_1: " << d_1.a << ", " << d_1.b << std::endl;

    Derived d_2 {7};
    std::cout << "d_2: " << d_2.a << ", " << d_2.b << std::endl;
    
    return 0;
}
