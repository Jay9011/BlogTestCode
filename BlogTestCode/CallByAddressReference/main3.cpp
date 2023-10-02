#include <iostream>
using namespace std;

void callByAddress(int* a)
{
	*a = *a + 2;
}

void callByReference(int& a)
{
	a = a + 2;
}

int main()
{
	int a = 1;
	callByAddress(&a);
	callByReference(a);
}