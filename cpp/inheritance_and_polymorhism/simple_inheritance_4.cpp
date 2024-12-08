#include <iostream>

//~ Базовий клас для прикладу із однаковими іменами
class Base
{
    public:
        int a {1};
        Base() { std:: cout << "Base Default constr." << std::endl; };
        Base(int a) : a {a} { std:: cout << "Base Overloaded constr." << std::endl; };
};

//~ Ліве крило
class Left : virtual public Base
{
    public:
        int  l_a {2};
        Left(int a, int b) : Base(a), l_a {b} { std:: cout << "Left Overloaded constr." << std::endl; };
};
//~ Праве крило
class Right : virtual public Base
{
    public:
        int  r_a {3};
        Right(int a, int b) : Base(a), r_a {b} {  std:: cout << "Right Overloaded constr." << std::endl; };
};

//~ Верхній клас, який успадковує і лівий клас, і правий
class Top : public Left, public Right
{
    public:
        int  t_a {4};
        //~ Конструктор із викликком конструткорів лівого та правого - буде викликано Base() - конструктор за замовчуванням
        Top(int lb_a, int l_a, int rb_a, int r_a, int t_a) : Left(lb_a, l_a), Right(rb_a, r_a), t_a {t_a} {
            std:: cout << "Top Overloaded constr." << std::endl;
                };

        //~ Конструктор із викликком контруткора базового класу
        Top(int b_a, int l_a, int r_a, int t_a) : Left(b_a, l_a), Right(b_a, r_a), Base {b_a}, t_a {t_a} {
            std:: cout << "Top Overloaded constr." << std::endl;
                };
};

int main()
{
    //~ Виклик першого конструктора із п'ятьма аргументами. В цьому випадку буде викликано Base() -
    //~ конструктор за замовчуванням, а виклики із Left(int a, int b) : Base(a) та Right(int a, int b) : Base(a)
    //~ будуть проігноровані
    
    Top t_object {11, 22, 33, 44, 55};

    //~ Уточнення можна додавати, але воно вже втратило сенс
    std::cout << t_object.Left::a << std::endl;
    std::cout << t_object.Right::a << std::endl;
    std::cout << t_object.a << std::endl;

    std::cout << t_object.l_a << std::endl;
    std::cout << t_object.r_a << std::endl;

    //~ Виклик конструктора із чотирма аргументами, із викликом Base {b_a} зі списку інціалізації
    
    Top t_object_2 {22, 33, 44, 55};
    
    
    return 0;
}

