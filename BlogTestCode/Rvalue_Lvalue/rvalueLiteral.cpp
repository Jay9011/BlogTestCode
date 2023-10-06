#include <iostream>
using namespace std;

int rtnInt() { return 1; }
int& refInt() {
	static int a = 10;
	return a;
}
int* rtnPtr()
{
	static int a = 10;
	return &a;
}

int main()
{
	int num = rtnInt();

	int arr[5];
	arr[0] = 1;
	int a = arr[0];

	int* ptr = &a;
	*ptr = 30;
	int b = *ptr;

	int* p = arr;

	refInt() = 20;
	*rtnPtr() = 20;
	cout << refInt() << endl;
	cout << *rtnPtr() << endl;
}