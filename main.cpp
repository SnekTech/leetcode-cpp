#include <iostream>
#include "codetop/q25.h"

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

    ListNode* list = ListNode::From({ 1, 2, 3, 4, 5 });

    s.reverseKGroup(list, 2);

    return 0;
}
