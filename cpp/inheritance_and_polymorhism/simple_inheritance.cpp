#include <iostream>

// Приклад розширення класу шляхом успадкування
// Клас А буде базовим класом
class A
{
    public:
        int var_a {1};
};

// Клас B розширює (або уточнює) клас A - поля класу А стають полями класу B, до яких додаються поля  класу B
class B: public A
{
    public:
        int var_b {2};

};

// Приклад агрегації - коли один клас мітить у собі об'єкт іншого класу
class C
{
    public:
        int var_c {3};
};

// Клас D містить у собі об'єкт класу C.
class D
{
    public:
        int var_d {4};
        class C c_object;
};


int main()
{
    B b_object;
    D d_object;

    std::cout << "Class B contains:\n\t" << b_object.var_a << ", " << b_object.var_b << std::endl;

    std::cout << "Class B adresses:\n" <<
                                            "\t&var_1: " << &b_object.var_a << std::endl <<
                                            "\t&var_2: " << &b_object.var_b << std::endl;


    std::cout << "Class D contains:\n\t" << d_object.c_object.var_c << ", " << d_object.var_d << std::endl;

    std::cout << "Class C adresses:\n" <<
                                            "\t&cobject.var_1: " << &d_object.c_object.var_c << std::endl <<
                                            "\t&var_2:         " << &d_object.var_d << std::endl;



    // Щоб "вичленити" клас С із класу D необхідно просто вказати достуб до відповідного поля
    C c_example = d_object.c_object;

    std::cout << "Extracted from D class C: " << c_example.var_c << std::endl;
    // Із класу, що використовує успадкування можна теж вичленити батьківський клас
    // В даному випадку відбувається "зрізання" - спочатку в пам'яті розташовуються дані батьківського класу, а потім успадкованого.
    // Відповідно, при зрізанні скопіюється перші байти, кількість рівна розміру батьківського класу
    A a_example = b_object;
    std::cout << "Extracted from B class A: " << a_example.var_a << std::endl;

    //~ Приклад із множинним успадкуванням
    //~ Клас F успадковує два прості класи A та  C
    class F : public A, public C
    {
        public:
            int var_f {7};
    };

    //~ Створюємо об'єкт класу
    F f_example;
    //~ Друкуємо розмір класу та положення елементів
    //~ Ви можете змінити тип поля класу А або С на char або short, щоб подивитись, чи зміниться розмір класу
    //~ В даному випадку він не зміниться при виборі типу даних меншого розміру - вирівнювання даних
    
    std::cout << "sizeof(F): " << sizeof(F) << std::endl;
    std::cout << "F class decomposition:\n" <<
                                            "\t&var_a" << &f_example.var_a << std::endl <<
                                            "\t&var_b" << &f_example.var_c << std::endl <<
                                            "\t&var_c" << &f_example.var_f << std::endl;
    C c_copy = f_example;
    std::cout << "c_copy size:  " << sizeof(c_copy) << std::endl;
    std::cout << "c_copy.var_c: " << c_copy.var_c << std::endl;
}
