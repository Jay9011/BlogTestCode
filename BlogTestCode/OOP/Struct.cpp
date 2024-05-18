#include <cstdlib>
#include <cstdio>

struct StructName	// 구조체 이름
{
	// 각 멤버 변수의 타입과 이름
	int Member1;
	float Member2;
	char Member3;
	bool Member4 = false;
};	// ※ 구조체 선언 끝엔 ;을 붙인다.

struct CPPStruct
{
	CPPStruct()
	{	// 생성자에서 초기화 가능
		Member1 = 0;
		Member2 = NULL;
	}
	~CPPStruct()
	{	// 소멸자에서 정리 가능
		if (Member2 != NULL)
		{
			delete[] Member2;
		}
	}

	// 멤버 함수
	int GetMember1() const
	{
		return Member1;
	}

	void PrintMember2() const
	{
		printf("%s\n", Member2);
	}

	// 멤버 변수
	int Member1 = 0;
	char* Member2;
};

struct CPP11Struct
{
	int Member1 = 0;
	char* Member2 = nullptr;	// nullptr로 초기화
};

class ClassName
{
public:
	ClassName();
	~ClassName();

private:

};

struct InheritanceStruct : public CPPStruct
{
	float Member3;
};

int main()
{
	struct StructName StructInstance;	// 구조체 변수 선언

	StructInstance.Member1 = 10;	// 구조체 변수의 멤버 변수에 접근
	StructInstance.Member2 = 3.14f;
	StructInstance.Member3 = 'A';

	int a = 10;

	int* pInt;							// int형 포인터 변수 선언
	struct StructName* pStructInstance;	// 구조체 포인터 변수 선언

	pInt = &a;							// int형 포인터 변수에 int형 변수의 주소를 대입
	pStructInstance = &StructInstance;	// 구조체 포인터 변수에 구조체 변수의 주소를 대입

	*pInt = 10;
	(*pStructInstance).Member1 = 10;	// 구조체 포인터 변수로 구조체 변수의 멤버 변수에 접근
	pStructInstance->Member1 = 10;		// 위와 같은 의미

	StructName StructInstance2;			// struct 키워드 생략 가능
	StructInstance2.Member1 = 20;
	StructInstance2.Member2 = 3.14f;
	StructInstance2.Member3 = 'B';

	InheritanceStruct InheritanceInstance;
	InheritanceInstance.Member1 = 10;
	InheritanceInstance.Member2 = nullptr;
	InheritanceInstance.Member3 = 3.14f;
}