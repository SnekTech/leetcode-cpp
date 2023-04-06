//
// Created by syf on 2023/4/7.
//
#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<unsigned long long> dp(target + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int x: nums)
            {
                if (x <= i)
                    dp[i] += dp[i - x];
            }

        return dp.back();
    }
};