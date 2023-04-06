#include <iostream>
#include "codetop/q377.h"

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
    vector<int> nums = { 1, 2, 3};
    s.combinationSum4(nums, 4);

    return 0;
}
