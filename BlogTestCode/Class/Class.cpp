#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass(){}
    // 복사 생성자
    MyClass(const MyClass& source)
	{
		cout << "복사 생성자 호출" << endl;
	}

};

void printMyClassValue(MyClass obj)
{
	cout << "printMyClassValue 함수 호출" << endl;
}

// 함수가 객체를 값으로 반환하는 경우
MyClass createMyClass()
{
    MyClass temp;
    return temp; // 복사 생성자가 호출됨
}

int main()
{
    // 객체를 다른 객체로 초기화하는 경우
    MyClass obj1;
    MyClass obj2 = obj1; // 복사 생성자 호출

    // 객체를 함수에 값으로 전달하는 경우
    printMyClassValue(obj1); // 복사 생성자 호출

    // 함수가 객체를 값으로 반환하는 경우
    MyClass obj3 = createMyClass(); // 복사 생성자 호출
}