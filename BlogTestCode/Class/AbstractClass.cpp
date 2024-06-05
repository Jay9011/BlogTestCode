#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base() {}

    virtual void pureVirtualFunction() = 0; // 순수 가상 함수
};

class Derived : public Base
{
public:
    ~Derived() override {}

    void pureVirtualFunction() override
    {
        cout << "Derived::pureVirtualFunction" << endl;
    }
};

int main()
{
    Base* ptr = new Derived();
    ptr->pureVirtualFunction();

    delete ptr;
}