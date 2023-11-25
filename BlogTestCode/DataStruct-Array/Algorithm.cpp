#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 6, 7, 8, 9, 10 };

	swap(vec, vec2);
}