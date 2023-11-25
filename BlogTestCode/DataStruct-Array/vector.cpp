#include <iostream>
#include <vector>

class MyType
{
public:
	MyType() {}
	MyType(int n) : num(n) {}
	MyType(int n, std::string str) : num(n), name(str) {}
	~MyType() {}

	std::string getName() const { return name; }
	int getNum() const { return num; }

private:
	int num = 0;
	std::string name = "None";
};

int main()
{
	std::vector<std::vector<std::vector<int>>> v(2, std::vector<std::vector<int>>(3, std::vector<int>(4)));

	// 배열의 각 요소에 값을 할당하는 부분
	int value = 0;
	for (auto& dim1 : v)
	{
		for (auto& dim2 : dim1)
		{
			for (auto& dim3 : dim2)
			{
				dim3 = value++;
			}
		}
	}

	// 배열의 각 요소를 출력하는 부분
	for (auto& dim1 : v)
	{
		for (auto& dim2 : dim1)
		{
			for (auto& dim3 : dim2)
			{
				std::cout << dim3 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::vector<MyType> v2(3, 0);
	v2.emplace_back(1, "One");

	for (auto& elem : v2)
	{
		std::cout << elem.getNum() << ' ' << elem.getName() << std::endl;
	}
}