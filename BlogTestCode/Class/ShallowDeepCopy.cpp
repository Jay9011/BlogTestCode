#include <iostream>

using namespace std;

class Shallow
{
public:
	int* data;

	Shallow(int d)
	{
		data = new int; // 동적 메모리 할당
		*data = d;
	}
	~Shallow()
	{
		delete data;
	}

	// 복사 생성자 (얕은 복사)
	Shallow(const Shallow& source) : data(source.data) {}
};

class Deep
{
public:
	int* data;

	Deep(int d)
	{
		data = new int; // 동적 메모리 할당
		*data = d;
	}
	~Deep()
	{
		delete data;
	}

	// 복사 생성자 (깊은 복사)
	Deep(const Deep& source)
	{
		data = new int; // 새로운 메모리 할당
		*data = *source.data;
	}
};

int main()
{
	Shallow obj1(2023);
	Shallow obj2 = obj1; // 얕은 복사 발생

	// obj1의 data 변경
	*(obj1.data) = 2024;

	cout << "Original data after change: " << *obj1.data << endl;	// 2024
	cout << "Copied data after change: " << *obj2.data << endl;		// 2024

	Deep obj3(2023);
	Deep obj4 = obj3; // 깊은 복사 발생

	// obj3의 data 변경
	*(obj3.data) = 2024;
	cout << "Original data after change: " << *obj3.data << endl;	// 2024
	cout << "Copied data after change: " << *obj4.data << endl;		// 2023
}
