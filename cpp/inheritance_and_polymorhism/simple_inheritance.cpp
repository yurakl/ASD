#include <iostream>

// Приклад розширення класу шляхом успадкування
// Клас А буде базовим класом
class A
{
    public:
        int var_1 {1};
};

// Клас B розширює (або уточнює) клас A - поля класу А стають полями класу B, до яких додаються поля  класу B
class B: public A
{
    public:
        int var_2 {2};

};

// Приклад агрегації - коли один клас мітить у собі об'єкт іншого класу
class C
{
    public:
        int var_1 {3};
};

// Клас D містить у собі об'єкт класу C.
class D
{
    public:
        int var_2 {4};
        class C c_object;
};


int main()
{
    B b_object;
    D d_object;

    std::cout << "Class B contains:\n\t" << b_object.var_1 << ", " << b_object.var_2 << std::endl;

    std::cout << "Class B adresses:\n" <<
                                            "\t&var_1: " << &b_object.var_1 << std::endl <<
                                            "\t&var_2: " << &b_object.var_2 << std::endl;


    std::cout << "Class D contains:\n\t" << d_object.c_object.var_1 << ", " << d_object.var_2 << std::endl;

    std::cout << "Class C adresses:\n" <<
                                            "\t&cobject.var_1: " << &d_object.c_object.var_1 << std::endl <<
                                            "\t&var_2:         " << &d_object.var_2 << std::endl;



    // Щоб "вичленити" клас С із класу D необхідно просто вказати достуб до відповідного поля
    C c_example = d_object.c_object;

    std::cout << "Extracted from D class C: " << c_example.var_1 << std::endl;
    // Із класу, що використовує успадкування можна теж вичленити батьківський клас
    // В даному випадку відбувається "зрізання" - спочатку в пам'яті розташовуються дані батьківського класу, а потім успадкованого.
    // Відповідно, при зрізанні скопіюється перші байти, кількість рівна розміру батьківського класу
    A a_example = b_object;
    std::cout << "Extracted from B class A: " << a_example.var_1 << std::endl;

}
