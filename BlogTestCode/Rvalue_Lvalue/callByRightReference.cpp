#include <iostream>
#include <vector>
using namespace std;

void fn(int& x)
{
	cout << "Lvalue reference\n";
}
void fn(const int& x)
{
	cout << "Rvalue\n";
}
void fn(int&& x)
{
	cout << "Rvalue reference\n";
}

const int& rvalueRef(int&& x)
{
	const int& y = x;
	return y;
}

const int& rvalueRef(const int& x)
{
	const int& y = x;
	return y;
}

int main()
{
	int x = 10;

	//fn(x); // Lvalue reference
	//fn(10); // Rvalue reference
	//fn(x + 10); // Rvalue reference

	const int& y = rvalueRef(10);
	cout << y << endl;
}