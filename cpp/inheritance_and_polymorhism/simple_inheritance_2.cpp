#include <iostream>

//~ Базовий клас для прикладу із однаковими іменами
class Base
{
    public:
        int a {1};
        void function(){std::cout << "Hello from Base" << std::endl;};
};

//~ Похідний клас
class Derived : public Base
{
    public:
        int a {2};
        void function(){std::cout << "Hello from Derived" << std::endl;};
        //~ Наступне для спроби виклику d_object.function();
        //~ void function(int a){std::cout << "Hello from Derived" << std::endl;};
};

int main()
{

    //~ Доступ до полів із однаковим іменем
    Derived d_object;

    //~ Будуть роздруковані дані похідного класу
    std::cout << "a: " << d_object.a << std::endl;
    d_object.function();

    //~ Будуть роздруковані дані базового класу
    std::cout << "a: " << d_object.Base::a << std::endl;
    d_object.Base::function();

    
    
    
    return 0;
}

