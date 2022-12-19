#include <iostream>

class Base {
public:
    void func1() const { std::cout << "Base::func1()" << std::endl; }
    virtual void func2() const { std::cout << "Base::func2()" << std::endl; }
};

class Derived : public Base {
public:
    void func1() const { std::cout << "Derived::func1()" << std::endl; }
    void func2() const { std::cout << "Derived::func2()" << std::endl; }
};

int main() {

    Base b; Derived d;
    Base *pb = &b; Base *pd = &d;
    Derived *pdd = &d;

    std::cout << "1" << std::endl;
    b.func1(); d.func1();
    b.func2(); d.func2();
    std::cout << "2" << std::endl;
    pb->func1(); pd->func1();
    pb->func2(); pd->func2();
    std::cout << "3" << std::endl;
    pdd->func1(); pdd->func2();

    return 0;
}