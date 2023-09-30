#include <iostream>
using namespace std;

void callByValue(int a)
{
	a = 2;
	cout << "callByValue: " << a << endl;
}

void callByAddress(int* a)
{
	*a = 3;
	cout << "callByAddress: " << *a << endl;
}

void callByReference(int& a)
{
	a = 4;
	cout << "callByReference: " << a << endl;
}

int main()
{
	int a = 1;
	//callByValue(a);
	//callByAddress(&a);
	callByReference(a);
	cout << "main a: " << a << endl;
}