#include <iostream>
#include <vector>

template<typename T>
using IntVector = std::vector<T>;

template<typename T1, typename T2>
class CustomDelegate
{
private:
	typedef void(*myFuncType)(T1, T2);
	// 템플릿 타입을 받아서 함수 포인터 타입을 정의하는 방법
	//using myFuncType = void(*)(T1, T2);

	std::vector<myFuncType> delegates;

public:
	void Bind(myFuncType func)
	{
		delegates.push_back(func);
	}

	void Broadcast(int a, int b)
	{
		for (myFuncType& func : delegates)
		{
			func(a, b);
		}
	}
};

void Add(int a, int b)
{
	std::cout << "Add: " << (a + b) << std::endl;
}

void Mul(int a, int b)
{
	std::cout << "Mul: " << (a * b) << std::endl;
}

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
	CustomDelegate<int, int> intDelegate;
	intDelegate.Bind(Add);
	intDelegate.Bind(Mul);

	intDelegate.Broadcast(1, 2);

	using MyClassAdd = void(MyClass::*)(int, int);
	MyClassAdd myClassAdd = &MyClass::Add;
	
	MyClass myClass;
	(myClass.*myClassAdd)(1, 2);
}