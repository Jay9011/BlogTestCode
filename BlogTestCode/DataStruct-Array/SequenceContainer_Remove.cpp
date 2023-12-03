#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::vector<int> vec = { 1, 2, 3, 3, 4, 5 };

	std::vector<int>::iterator vi = vec.begin();
	//std::vector<int>::iterator ve = vec.end();

	//for (; vi != ve; ++vi)
	//{
	//	if (*vi == 3)
	//	{
	//		vec.erase(vi);
	//	}
	//}


	//for (; vi != vec.end();)
	//{
	//	if (*vi == 3)
	//	{
	//		vi = vec.erase(vi);
	//	}
	//	else
	//	{
	//		vi++;
	//	}
	//}

	//std::vector<int>::iterator vir = remove(vec.begin(), vec.end(), 3);

	//std::cout << *vir << std::endl;

	//for (; vir != vec.end(); vir++)
	//{
	//	std::cout << *vir << " ";
	//}

	//std::cout << std::endl;

	vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());

	for (auto i : vec)
	{
		std::cout << i << " ";
	}

	//std::list<int> lst = { 1, 2, 3, 4, 5 };
	//
	//std::list<int>::iterator li = lst.begin();
	//std::list<int>::iterator le = lst.end();

	//for (; li != le; ++li)
	//{
	//	if (*li == 3)
	//	{
	//		lst.erase(li);
	//	}
	//}

	//std::list<int>::reverse_iterator lri = lst.rbegin();
	//std::list<int>::reverse_iterator lre = lst.rend();

	//for (; lri != lre; ++lri)
	//{
	//	if (*lri == 3)
	//	{
	//		lst.erase(lri);
	//	}
	//}

	//for (auto i : lst)
	//{
	//	std::cout << i << " ";
	//}

}