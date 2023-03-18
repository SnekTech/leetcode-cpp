//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q53_1_H
#define LEETCODE_CPP_Q53_1_H

#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        if (nums[0] == 1 && nums[n - 2] == n - 1)
        {
            return 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (i != nums[i])
            {
                return i;
            }
        }

        return n - 1;
    }
};

#endif //LEETCODE_CPP_Q53_1_H
