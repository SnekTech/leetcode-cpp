#include <iostream>
#include "codetop/q417.h"

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
    vector<vector<int>> heights = {
        {1},
    };
    auto result = s.pacificAtlantic(heights);

    return 0;
}
