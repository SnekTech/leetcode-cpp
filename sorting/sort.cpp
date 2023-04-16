//
// Created by syf on 2023/4/12.
//

#include "sort.h"

using namespace std;
using namespace Snek;

void Snek::BubbleSort(vector<int>& nums)
{
    auto n = nums.size();

    for (auto i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
}

void Snek::SelectionSort(vector<int>& nums)
{
    auto n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[minIndex])
                minIndex = j;

        swap(nums[i], nums[minIndex]);
    }
}