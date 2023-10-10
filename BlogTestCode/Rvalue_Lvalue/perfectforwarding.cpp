#include <iostream>
#include <utility>

void foo(int& x) { std::cout << "lvalue ref: " << x << std::endl; }
void foo(int&& x) { std::cout << "rvalue ref: " << x << std::endl; }

template <typename T>
void wrapper(T&& arg)
{
    foo(std::forward<T>(arg));
}

int main() {
    int a = 5;
    wrapper(a);  // Output: lvalue ref: 5
    wrapper(10); // Output: rvalue ref: 10
}