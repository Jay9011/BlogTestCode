#include <iostream>

int Add(int a, int b)
{
    return a + b;
}

int Multiply(int a, int b)
{
    return a * b;
}

// 함수 포인터를 반환하는 함수
int (*GetOperation(char op))(int, int)
{
    if (op == '+') 
    {
        return Add;
    }
    else if (op == '*') 
    {
        return Multiply;
    }

    return nullptr;
}

int Operation(int a, int b, int (*callBack)(int, int))
{
	return callBack(a, b);
}

int main()
{
    int n = Operation(5, 3, Add);
    std::cout << "결과: " << n << std::endl;

    n = Operation(5, 3, Multiply);
    std::cout << "결과: " << n << std::endl;

    //int(*operation)(int, int) = GetOperation('+');

    //if (operation != nullptr) 
    //{
    //    std::cout << "결과: " << operation(5, 3) << std::endl; // Add 함수 호출
    //}

    //operation = GetOperation('*');
    //if (operation != nullptr) 
    //{
    //    std::cout << "결과: " << operation(5, 3) << std::endl; // Multiply 함수 호출
    //}
}
