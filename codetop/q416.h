//
// Created by syf on 2023/4/5.
//

#pragma once

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums, int index, int target)
    {
        if (target == 0)
            return true;
        if (index < 0 || target < 0)
            return false;

        if (memo[index][target] != -1)
            return memo[index][target];

        bool can = canPartition(nums, index - 1, target) ||
            canPartition(nums, index - 1, target - nums[index]);

        memo[index][target] = can;
        return can;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int n = nums.size();
        for (int i = 0; i < n; i++)
            memo.push_back(vector<int>(sum / 2 + 1, -1));

        return canPartition(nums, nums.size() - 1, sum / 2);
    }
};