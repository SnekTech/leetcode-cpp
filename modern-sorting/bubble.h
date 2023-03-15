//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_BUBBLE_H
#define LEETCODE_CPP_BUBBLE_H

#include <vector>

using Arr = std::vector<int>;

void BubbleSort(Arr arr)
{
    using std::swap;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size() - i; j++)
        {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

#endif //LEETCODE_CPP_BUBBLE_H
