#include <iostream>
#include <array>
int main()
{
    std::array<std::array<std::array<int, 4>, 3>, 2> arr2;

    // �迭�� �� ��ҿ� ���� �Ҵ��ϴ� �κ�
    int value = 0;
    for (auto dim1_it = arr2.begin(); dim1_it != arr2.end(); dim1_it++)
    {
        for (auto dim2_it = dim1_it->begin(); dim2_it != dim1_it->end(); dim2_it++)
        {
            for (auto dim3_it = dim2_it->begin(); dim3_it != dim2_it->end(); dim3_it++)
            {
                *dim3_it = value++;
            }
        }
    }

    // �迭�� �� ��Ҹ� ����ϴ� �κ�
    for (auto dim1_it = arr2.begin(); dim1_it != arr2.end(); dim1_it++)
    {
        for (auto dim2_it = dim1_it->begin(); dim2_it != dim1_it->end(); dim2_it++)
        {
            for (auto dim3_it = dim2_it->begin(); dim3_it != dim2_it->end(); dim3_it++)
            {
                std::cout << *dim3_it << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}