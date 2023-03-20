#include <iostream>
#include "modern-sorting/bubble.h"
#include "codetop/q215.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    Arr arr = {3,2,1};
    BubbleSort(arr);

	Solution s;
	vector<int> v = { 1,2 ,3};

	auto result = s.findKthLargest(v, 2);
	std::cout << result << std::endl;
    return 0;
}
