#include <iostream>
#include <functional>

class MyClass
{
public:
	void Add(int a, int b)
	{
		std::cout << "MyClass Add: " << (a + b) << std::endl;
	}
};

void Add(int a, int b)
{
	std::cout << "Add: " << (a + b) << std::endl;
}

int main()
{
	std::function<void(int, int)> FuncPtr;

	FuncPtr = Add;
	FuncPtr(1, 2);

	MyClass myClass;
	FuncPtr = std::bind(&MyClass::Add, myClass, std::placeholders::_1, std::placeholders::_2);
	FuncPtr(1, 2);
}