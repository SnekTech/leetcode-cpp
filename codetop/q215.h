//
// Created by syf on 2023/3/20.
//

#ifndef LEETCODE_CPP_Q215_H
#define LEETCODE_CPP_Q215_H

#include <vector>

using std::vector;

class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		int n = nums.size();
		int target = n - k;

		int start = 0, end = n - 1;
		while (true)
		{
			int pivotIndex = partition(nums, start, end);
			if (pivotIndex == target)
			{
				return nums[pivotIndex];
			}

			if (pivotIndex < target)
			{
				start = pivotIndex + 1;
			}
			else
			{
				end = pivotIndex - 1;
			}
		}
	}

	static int partition(vector<int>& nums, int start, int end)
	{
		int pivot = nums[start];
		int less = start + 1;
		int more = end;

		while (true)
		{
			while (less <= end && nums[less] <= pivot)
			{
				less++;
			}
			while (more >= start + 1 && nums[more] > pivot)
			{
				more--;
			}

			if (less >= more) break;

			std::swap(nums[less], nums[more]);
		}

		std::swap(nums[more], nums[start]);
		return more;
	}
};

#endif //LEETCODE_CPP_Q215_H
