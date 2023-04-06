#include <iostream>
#include "codetop/q518.h"

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
    vector<int> coins = { 1, 2, 5};
    s.change(5, coins);

    return 0;
}
