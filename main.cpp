#include <iostream>
#include "codetop/q416.h"

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
    vector<int> nums = {1, 5, 11,5};
    bool result = s.canPartition(nums);

    return 0;
}
