#include <iostream>
#include "codetop/q216.h"

using namespace std;

template<typename T>
static void print(T arg)
{
    std::cout << arg << std::endl;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;

    Solution s;
    vector<int> v = { 1, 1, 2 };
    s.combinationSum3(9, 45);

    return 0;
}
