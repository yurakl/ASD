#include <iostream>

// Приклад роботи конструкторів та деструкторів

class A {
public:
    int var_1;

    // Перевантажений конструктор класу A

    A(int value) : var_1(value) {
        std::cout << "Constructor A called with var_1 = " << var_1 << std::endl;
    }

    ~A() {
        std::cout << "Destructor A called\n";
    }
};

class B : public A {
public:
    int var_2;

    // Перевантажений конструктор класу B - у списку ініціалізації викликаємо конструктор базового класу

    B(int value1, int value2) : A(value1), var_2(value2) {
        std::cout << "Constructor B called with var_2 = " << var_2 << std::endl;
    }

    ~B() {
        std::cout << "Destructor B called\n";
    }
};

class C {
public:
    int var_3;

    // Перевантажений конструктор класу С

    C(int value) : var_3(value) {
        std::cout << "Constructor C called with var_3 = " << var_3 << std::endl;
    }

    ~C() {
        std::cout << "Destructor C called\n";
    }
};

class D {
public:
    C c_object; // агрегація класу C
    int var_4;

    // Перевантажений конструктор класу D - у списку ініціалізації створюємо вкладений об'єкт класу С - тобто викликаємо перевантажений конструктор класу А

    D(int value3, int value4) : c_object(value3), var_4(value4) {
        std::cout << "Constructor D called with var_4 = " << var_4 << std::endl;
    }

    ~D() {
        std::cout << "Destructor D called\n";
    }
};

int main() {

    // при створенні об'єкту дочірнього класу спочатку буде виконаний конструктор батьківського
    std::cout << "Creating object of class B:\n";
    B b_object(10, 20);

    // Конструткор вкладеного класу буде викликаний першим, оскільк він вказаний у списку інціалізації.
    std::cout << "\nCreating object of class D:\n";
    D d_object(30, 40);


    return 0;
}
