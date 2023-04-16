//
// Created by syf on 2023/4/16.
//

#include "sort.h"

using namespace Snek;
using std::swap;

static int Partition(vector<int>& nums, int left, int right)
{
    // [v, < v, > v]
    // [0, 1...j, j + 1...i - 1]
    const int v = nums[left];
    int j = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (nums[i] < v)
        {
            swap(nums[j + 1], nums[i]);
            j++;
        }
    }

    swap(nums[left], nums[j]);
    return j;
}

static void Quick(vector<int>& nums, int left, int right)
{
    if (left >= right)
        return;

    int pivot = Partition(nums, left, right);
    Quick(nums, left, pivot - 1);
    Quick(nums, pivot + 1, right);
}

void Snek::QuickSort(vector<int>& nums)
{
    Quick(nums, 0, (int)nums.size() - 1);
}