#include <cstdio>

#pragma pack(4) // 4byte 경계로 정렬

struct Struct01
{
	char char1;		// 1byte
	int int1;		// 4byte
	float float1;	// 4byte
	double double1;	// 8byte
	int int2;		// 4byte
	// 총 21byte로 예상
	// 하지만, 1 + 3(padding) + 4 + 4 + 4(padding) + 8 + 4 + 4(padding) = 32 byte
};

#pragma pack(push, 1) // 1byte 경계로 정렬

struct Struct02
{
	// 정렬된 구조체
	char char1;		// 1byte
	int int1;		// 4byte
	int int2;		// 4byte
	float float1;	// 4byte
	double double1;	// 8byte
	// 1 + 3(padding) + 4 + 4 + 4 + 8 = 24byte
};

#pragma pack(pop) // 정렬 설정을 이전 상태로 복구

struct Struct03
{
	// 제일 큰 자료형이 int인 경우
	char char1;		// 1byte
	int int1;		// 4byte
	float float1;	// 4byte
	int int2;		// 4byte
};

class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	char char1;		// 1byte
	int int1;		// 4byte
	float float1;	// 4byte
	double double1;	// 8byte
	int int2;		// 4byte
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
	printf("구조체 1의 크기: %d byte\n", sizeof(Struct01));	// 32byte
	printf("정렬된 구조체의 크기: %d byte\n", sizeof(Struct02));	// 24byte
	printf("int가 제일 큰 구조체의 크기: %d byte\n", sizeof(Struct03));	// 16byte

	printf("클래스의 크기: %d byte\n", sizeof(MyClass));	// 24byte
}