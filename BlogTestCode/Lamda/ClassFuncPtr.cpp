#include <iostream>

class MyClass
{
public:
	void Add(int a, int b)
	{
		std::cout << "MyClass Add: " << (a + b) << std::endl;
	}
};

int main()
{
	void (MyClass::*FuncPtr)(int, int) = &MyClass::Add;

	MyClass myClass1;
	(myClass1.*FuncPtr)(1, 2);

	MyClass myClass2;
	(myClass2.*FuncPtr)(1, 2);
}