//
// Created by syf on 2023/4/5.
//

#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (auto x: nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int n = nums.size();
        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        for (int j = 1; j <= target; j++)
            dp[0][j] = nums[0] == target;

        for (int i = 1; i < n; i++)
            for (int j = 1; j <= target; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }

        return dp[n - 1][target];
    }
};