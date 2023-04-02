#include <iostream>
#include "codetop/q93.h"

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
    s.restoreIpAddresses("25525511135");

    return 0;
}
