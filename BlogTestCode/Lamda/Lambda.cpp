#include <iostream>
using namespace std;

int main()
{
	auto f = [](int x, int y) { return x + y; };

	int i = ([](int x, int y) { return x + y; })(3, 4);
	cout << i << endl;
}
