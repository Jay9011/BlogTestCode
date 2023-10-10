#include <iostream>
#include <vector>
using namespace std;

class MyCharacter
{
public:
	MyCharacter()
	{
		data = new char[10];
		strcpy_s(data, 10, "Hello");
		
		cout << "Constructor: " << static_cast<void*>(data) << '\n';
	}

	MyCharacter(const MyCharacter& other)
	{
		data = new char[10];
		strcpy_s(data, 10, other.data);

		cout << "Copy Constructor: " << static_cast<void*>(data) << '\n';
	}

	MyCharacter(MyCharacter&& other) noexcept
	{
		data = other.data;
		other.data = nullptr;

		cout << "Move Constructor: " << static_cast<void*>(data) << '\n';
	}

	MyCharacter& operator=(const MyCharacter& other)
	{
		if (this != &other)
		{
			delete[] data;

			data = new char[10];
			strcpy_s(data, 10, other.data);
		}

		cout << "Copy Assignment: " << static_cast<void*>(data) << '\n';

		return *this;
	}

	MyCharacter& operator=(MyCharacter&& other) noexcept
	{
		if (this != &other)
		{
			delete[] data;

			data = other.data;
			other.data = nullptr;
		}

		cout << "Move Assignment: " << static_cast<void*>(data) << '\n';

		return *this;
	}

	~MyCharacter()
	{
		if (data != nullptr)
		{
			delete[] data;
			cout << "Destructor: " << static_cast<void*>(data) << '\n';
		}
		else
		{
			cout << "Destructor: nullptr\n";
		}
	}

public:
	char* data;
};

MyCharacter&& rvalueRef(MyCharacter&& x)
{
	return std::move(x);
}

void mySwap(MyCharacter&& x, MyCharacter&& y)
{
	MyCharacter tmp = std::move(x);
	x = std::move(y);
	y = std::move(tmp);
}

int main()
{
	/*vector<MyCharacter> characters;
	characters.push_back(MyCharacter());

	cout << characters[0].data << '\n';

	MyCharacter x;
	MyCharacter&& y = rvalueRef(std::move(x));
	cout << static_cast<void*>(y.data) << '\n';*/

	MyCharacter x;
	MyCharacter y;
	cout << "x: " << static_cast<void*>(x.data) << ", y: " << static_cast<void*>(y.data) << '\n';
	mySwap(std::move(x), std::move(y));
	cout << "x: " << static_cast<void*>(x.data) << ", y: " << static_cast<void*>(y.data) << '\n';
}