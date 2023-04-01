//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q213_H
#define LEETCODE_CPP_Q213_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        if (n == 1)
            return dp[0];

        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i <= n - 2; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        int result = dp[n - 2];

        dp.resize(n, -1);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(dp[n - 1], nums[n - 2]);
        for (int i = n - 3; i > 0; i--)
        {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        result = max(result, dp[1]);

        return result;
    }
};

#endif //LEETCODE_CPP_Q213_H
