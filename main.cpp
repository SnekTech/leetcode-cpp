#include <iostream>
#include "codetop/q32.h"

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
    s.longestValidParentheses("(()");

    return 0;
}
