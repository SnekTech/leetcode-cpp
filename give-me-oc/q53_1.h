//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q53_1_H
#define LEETCODE_CPP_Q53_1_H

#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int targetIndex = binarySearch(nums, target);
        if (targetIndex == -1)
        {
            return 0;
        }

        int count = 1;
        // find left
        for (int i = targetIndex - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        // find right
        for (int i = targetIndex + 1; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        return count;
    }

    static int binarySearch(const vector<int>& nums, int key)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midVal = nums[mid];
            if (key == midVal)
            {
                return mid;
            }

            if (key < midVal)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
};


#endif //LEETCODE_CPP_Q53_1_H
