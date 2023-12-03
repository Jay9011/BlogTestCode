#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	std::stack<int, std::vector<int>> s(v);
	std::stack<int, std::vector<int>> s1(s);

	for (int i = 0; i < 7; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
}