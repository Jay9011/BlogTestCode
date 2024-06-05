#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream iss("test 123 aaa 456");
    std::string s1, s2;
    int i1, i2;
    iss >> s1 >> i1 >> s2 >> i2; // 공백을 기준으로 문자열을 파싱하고, 변수 형식에 맞게 변환

    std::cout << s1 << '\n';
    std::cout << i1 << '\n';
    std::cout << s2 << '\n';
    std::cout << i2 << '\n';
}