#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    Base()
    {
	    cout << "Base 생성자 호출" << endl;
    }
    virtual ~Base()
	{
        cout << "Base 소멸자 호출" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
	    cout << "Derived 생성자 호출" << endl;
    }
    ~Derived() override
	{
        cout << "Derived 소멸자 호출" << endl;
    }
};

int main()
{
	Base* ptr = new Derived();

	delete ptr;
}