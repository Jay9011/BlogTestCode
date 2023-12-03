#include <iostream>
#include <vector>
#include <list>
#include <queue>

int main()
{
	//std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
	//std::queue<int, std::vector<int>> qv(v);

	//for (int i = 0; i < 7; i++)
	//{
	//	std::cout << qv.front() << std::endl;
	//	qv.pop();
	//}



	std::list<int> l = { 1, 2, 3, 4, 5, 6, 7 };
	std::queue<int, std::list<int>> q(l);

	for (int i = 0; i < 7; i++)
	{
		std::cout << q.front() << std::endl;
		q.pop();
	}
}