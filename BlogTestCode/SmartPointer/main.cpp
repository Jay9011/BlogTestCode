#include <iostream>
#include <utility>
using namespace std;

template <typename T>
class CustomSmartPointer
{
public:
	// 생성자에서 자원을 할당합니다.
	CustomSmartPointer(T* ptr = nullptr) : ptr(ptr)
	{
		cout << *ptr << "번 자원을 할당합니다." << endl;
	}
	// 소멸자에서 자원을 해제합니다.
	~CustomSmartPointer()
	{
		if(ptr != nullptr)
		{
			cout << *ptr << "번 자원을 해제합니다." << endl;
			delete ptr;
		}
	}

	// 복사 생성자와 대입 연산자를 삭제합니다.
	CustomSmartPointer(const CustomSmartPointer&) = delete;
	CustomSmartPointer& operator=(const CustomSmartPointer&) = delete;

	// 이동 생성자와 이동 대입 연산자로 소유권 이전을 정의합니다.
	CustomSmartPointer(CustomSmartPointer&& other)
		: ptr(other.ptr)
	{
		other.ptr = nullptr;
	}
	CustomSmartPointer& operator=(CustomSmartPointer&& other)
	{
		if (this != &other)
		{
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		return *this;
	}

	// 포인터처럼 사용할 수 있도록 * 연산자와 -> 연산자를 오버로딩합니다.
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

private:
	T* ptr;
};

void test()
{
	CustomSmartPointer<int> p1(new int(1)); // p1이 자원을 할당합니다.
	
	CustomSmartPointer<int> p2(move(p1)); // p2로 소유권을 이전합니다.
	// CustomSmartPointer<int> p3 = p2; // 컴파일 에러! 복사 불가능
	CustomSmartPointer<int> p3(new int(2));

	cout << *p2 << endl; // 포인터처럼 사용.
}

int main()
{
	test();
}