#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
	istream_iterator<int> in_it(cin);
	cout << "in_it = " << *in_it << endl;

	ostream_iterator<int> out_it(cout, " (out_it)\n");
	*out_it = 1;
	*out_it = 2;

	vector<int> vec = { 1, 2, 3 };
	vector<int>::iterator it = vec.begin();
	vector<int>::reverse_iterator rit = vec.rbegin();
	vector<int>::const_iterator cit = vec.cbegin();
	vector<int>::const_reverse_iterator crit = vec.crbegin();

	it++; it--;
	cout << "it[2] = " << it[2] << endl;
	rit++; rit--;
	cout << "rit[2] = " << rit[2] << endl;
	cit++; cit--;
	// *cit = 4; // cit는 상수 이터레이터라서 쓰기가 불가능
	cout << "cit[2] = " << cit[2] << endl;
	crit++; crit--;
	// *crit = 4; // crit는 상수 이터레이터라서 쓰기가 불가능
	cout << "crit[2] = " << crit[2] << endl;

	list<int> lst = { 1, 2, 3 };
	list<int>::iterator it1 = lst.begin();
	list<int>::reverse_iterator rit1 = lst.rbegin();
	it1++; it1--;
	rit1++; rit1--;
	//cout << "it1[2] = " << it1[2] << endl; // 임의 접근 불가능
	cout << "*it1 = " << *it1 << endl; // *it1 = 1

	forward_list<int> flst = { 1, 2, 3 };
	forward_list<int>::iterator it2 = flst.begin();
	it2++;
	// it2--; // 단방향 이터레이터는 -- 연산자를 지원하지 않음
	*it2 = 4;
	cout << "*it2 = " << *it2 << endl; // *it2 = 4

	insert_iterator<vector<int>> iit(vec, vec.begin() + 1);
	*iit = 4;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
}