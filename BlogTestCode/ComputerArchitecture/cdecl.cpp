#include <iostream>

void _cdecl func1(int a, int b)
{
	a + b;
}

void _stdcall func2(int a, int b)
{
	a + b;
}

int main()
{
	func1(1, 2);
	func2(1, 2);
}