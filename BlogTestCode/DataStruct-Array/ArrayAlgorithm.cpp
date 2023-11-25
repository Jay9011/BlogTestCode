#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::array<int, 5> a = { 1, 2, 3, 4, 5 };
	std::list<int> l = { 1, 2, 3, 4, 5 };
	std::deque<int> d = { 1, 2, 3, 4, 5 };
	std::map<int, int> m = { {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5} };

	std::remove(v.begin(), v.end(), 3);
	std::remove(a.begin(), a.end(), 3);

	//std::remove(l.begin(), l.end(), 3);
	l.erase(std::remove(l.begin(), l.end(), 3), l.end());

	std::remove(d.begin(), d.end(), 3);

	//std::remove(m.begin(), m.end(), 3); // error

	for (auto& i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	for (auto& i : a)
		std::cout << i << " ";
	std::cout << std::endl;

	for (auto& i : l)
		std::cout << i << " ";
	std::cout << std::endl;

	for (auto& i : d)
		std::cout << i << " ";
	std::cout << std::endl;

}