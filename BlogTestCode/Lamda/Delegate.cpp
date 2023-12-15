#include <iostream>
#include <vector>

class CustomDelegate
{
private:
	using FuncType = void(*)();
	std::vector<FuncType> delegates;

public:
	void Bind(FuncType func)
	{
		delegates.push_back(func);
	}

	void Broadcast()
	{
		for (void(*&func)() : delegates)
		{
			func();
		}
	}
};

void func1()
{
	std::cout << "func1" << '\n';
}
void func2()
{
	std::cout << "func2" << '\n';
}

int main()
{
	CustomDelegate customDelegate;

	customDelegate.Bind(func1);
	customDelegate.Bind(func2);

	customDelegate.Broadcast();
}