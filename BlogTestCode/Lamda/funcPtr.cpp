#include <iostream>

int Add(int a, int b)
{
    return a + b;
}

int Multiply(int a, int b)
{
    return a * b;
}

// �Լ� �����͸� ��ȯ�ϴ� �Լ�
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
    std::cout << "���: " << n << std::endl;

    n = Operation(5, 3, Multiply);
    std::cout << "���: " << n << std::endl;

    //int(*operation)(int, int) = GetOperation('+');

    //if (operation != nullptr) 
    //{
    //    std::cout << "���: " << operation(5, 3) << std::endl; // Add �Լ� ȣ��
    //}

    //operation = GetOperation('*');
    //if (operation != nullptr) 
    //{
    //    std::cout << "���: " << operation(5, 3) << std::endl; // Multiply �Լ� ȣ��
    //}
}
