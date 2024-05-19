#include <cstdio>

int main()
{
	// 리틀 엔디안 디버깅에서 확인
	int Value = 0x12345678;

	printf("%p\n", &Value);
}