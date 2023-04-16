#include <iostream>
#include "sorting/sort.h"

using namespace Snek;

template<typename T>
static void print(T arg)
{
    std::cout << arg << std::endl;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr = {5,1,2,3};

    Snek::BubbleSort(arr);

    return 0;
}
