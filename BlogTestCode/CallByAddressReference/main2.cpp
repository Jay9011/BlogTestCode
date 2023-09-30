#include <iostream>
using namespace std;

void callByAddress(int* a)
{
	*a = 2;
	cout << "callByAddress:\t\t" << &a << "\n";
	cout << "callByAddress-value:\t" << a << "\n\n";
}

void callByReference(int& a)
{
	a = 2;
	cout << "callByReference:\t" << &a << "\n\n";
}

int main()
{
	int a = 1;
	cout << "main a Address:\t\t" << &a << "\n\n";
	callByAddress(&a);
	callByReference(a);
}