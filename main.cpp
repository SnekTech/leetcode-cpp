#include <iostream>
#include "codetop/q5.h"

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
    auto result = s.longestPalindrome("babad");

    return 0;
}
