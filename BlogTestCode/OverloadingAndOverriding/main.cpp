#include <iostream>

class Calculator
{
public:
	static int Divide(int a, int b)
	{
		return a / b;
	}
	static int Divide(int a, int b, int& remainder)
	{
		remainder = a % b;
		return a / b;
	}
	static int Divide(int a, int b, float& remainder)	// 매개변수의 타입이 다르면 오버로딩이 가능
	{
		remainder = static_cast<float>(a % b);
		return a / b;
	}

	// static int Divide(int b, int a)	// 매개변수의 이름은 메서드의 시그니처에 포함되지 않음
	// {
	// 	return b / a;
	// }
};

int main()
{
	int num1 = 10, num2 = 3;

	int result = Calculator::Divide(num1, num2);

	std::cout << num1 << " / " << num2 << " = " << result << '\n';

	int remainder;
	result = Calculator::Divide(num1, num2, remainder);

	std::cout << num1 << " / " << num2 << " = " << result << " (" << remainder << ")\n";
}