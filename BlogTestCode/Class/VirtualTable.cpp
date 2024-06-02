#include <iostream>

using namespace std;

class Base
{
public:
	void BaseOnlyFunc()
	{
		cout << "BaseOnlyFunc" << endl;
	}
	virtual void VirtualFunc()
	{
		cout << "Base::VirtualFunc" << endl;
	}
	virtual void VirtualFunc2()
	{
		cout << "Base::VirtualFunc2" << endl;
	}

	void NonVirtualFunc()
	{
		cout << "Base::NonVirtualFunc" << endl;
	}

	virtual ~Base() {}
};

class Derived : public Base
{
public:
	void DerivedOnlyFunc()
	{
		cout << "DerivedOnlyFunc" << endl;
	}
	virtual void VirtualFunc()
	{
		cout << "Derived::VirtualFunc" << endl;
	}

	void NonVirtualFunc()
	{
		cout << "Derived::NonVirtualFunc" << endl;
	}

	virtual ~Derived() {}
};

int main()
{
	Base* base = new Derived();

	base->BaseOnlyFunc();
	base->VirtualFunc();
	base->VirtualFunc2();
	base->NonVirtualFunc();

	delete base;
}