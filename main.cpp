#include <iostream>
#include "codetop/q46.h"

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
    vector<int> v = { 1, 2, 3 };
    s.permute(v);

    return 0;
}
