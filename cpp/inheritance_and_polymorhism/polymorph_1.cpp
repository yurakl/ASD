#include <iostream>

//~ Базовий клас  
class Base
{
    public:
        int  a {1};
        virtual void print() { std::cout << "Base" << std::endl; };
};

//~ Ліве крило
class Left : virtual public Base
{
    public:
        int  l_a {2};
        virtual void print() { std::cout << "Left" << std::endl; };
};

//~ Праве крило
class Right : virtual public Base
{
    public:
        int  r_a {3};
        virtual void print() { std::cout << "Right" << std::endl; }; 
};

//~ Верхній клас, який успадковує і лівий клас, і правий
class Top : public Left, public Right
{
    public:
        int  t_a {4};
        void print() { std::cout << "Top" << std::endl; };
};

int main()
{
    Base *ptr[4];
    ptr[0] = new Right;
    ptr[1] = new Top;
    ptr[2] = new Left;
    ptr[3] = new Base;

    //~ Для спроби доступу до поля похідного класу через вказівник на базовий
    //~ ptr[2]->l_a = 1;

    //~ Цикл по вказівникам - має бути викликана функція кожного із типів
    for (const auto& element : ptr)
    {
        element->print();
    }

    //~ Далі цикл для висвітлення динамчного привелення типів
    for (int i = 0; i < 4; ++i) {
        ptr[i]->print(); // Виведення типу об'єкта через віртуальну функцію

        // Динамічне приведення до Top
        if (Top* topPtr = dynamic_cast<Top*>(ptr[i])) {
            std::cout << "Object is of type Top with t_a = " << topPtr->t_a << std::endl;
        }
        else if (Left* leftPtr = dynamic_cast<Left*>(ptr[i])) {
            std::cout << "Object is of type Left with l_a = " << leftPtr->l_a << std::endl;
        }
        else if (Right* rightPtr = dynamic_cast<Right*>(ptr[i])) {
            std::cout << "Object is of type Right with r_a = " << rightPtr->r_a << std::endl;
        }
        else {
            std::cout << "Object is of type Base with a = " << ptr[i]->a << std::endl;
        }
    }
     
}
