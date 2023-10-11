#include <iostream>
using namespace std;

class MyCharacter
{
public:
	int id;
	int* data;
};

MyCharacter&& returnRvalueRef()
{
	MyCharacter x;
	return std::move(x);
}

void rvalueRef(int&& x)
{
}

void mySwap(MyCharacter&& x, MyCharacter&& y)
{
	MyCharacter tmp = std::move(x);
	x = std::move(y);
	y = std::move(tmp);
}

void callOverloading(int& x)
{
	cout << "L-value Ref\n";
}
void callOverloading(int&& x)
{
	cout << "R-value Ref\n";
}
void callOverloading(const int& x)
{
	cout << "Const L-value Ref\n";
}

int main()
{
	//MyCharacter x;
	//MyCharacter y;
	//rvalueRef(std::move(x).id);

	//int id = MyCharacter().id;

	int a = 123;
	callOverloading(a);	// L-value Ref
	callOverloading(123);	// R-value Ref
	callOverloading(std::move(a));	// R-value Ref

	const int b = 200;
	callOverloading(b);	// Const L-value Ref
}