#include <iostream>

//~ Базовий клас для прикладу із однаковими іменами
class Base
{
    public:
        int a {1};
        Base(int a) : a {a} {};
};

//~ Ліве крило
class Left : public Base
{
    public:
        int  l_a {2};
        Left(int a, int b) : Base(a), l_a {b} {};
};
//~ Праве крило
class Right : public Base
{
    public:
        int  r_a {3};
        Right(int a, int b) : Base(a), r_a {b} {};
};

//~ Верхній клас, який успадковує і лівий клас, і правий
class Top : public Left, public Right
{
    public:
        int  t_a {4};
        Top(int lb_a, int l_a, int rb_a, int r_a, int t_a) : Left(lb_a, l_a), Right(rb_a, r_a), t_a {t_a} {};
};

int main()
{

    Top t_object {11, 22, 33, 44, 55};

    //~ Додавання уточнення - змінну якого саме базового класу нам потрібно отримати
    std::cout << t_object.Left::a << std::endl;
    std::cout << t_object.Right::a << std::endl;
    
    
    
    
    return 0;
}

