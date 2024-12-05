#include <iostream>

class Base {
protected:
    int protected_var;

public:
    Base(int value) : protected_var(value) {}

    void showProtectedVar() const {
        std::cout << "Protected variable: " << protected_var << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(int value) : Base(value) {}

    void modifyProtectedVar(int newValue) {
        protected_var = newValue;
    }
};

class Aggregated {
public:
    Base base_object;

    Aggregated(int value) : base_object(value) {}

    void accessBaseVar() {
        base_object.showProtectedVar();
        // base_object.protected_var = 10; // Помилка: немає прямого доступу до protected
    }
};

int main() {
    Derived derived_object(5);
    derived_object.showProtectedVar();
    derived_object.modifyProtectedVar(10);
    derived_object.showProtectedVar();

    Aggregated aggregated_object(15);
    aggregated_object.accessBaseVar();

    return 0;
}
