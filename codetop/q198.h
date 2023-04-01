//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q198_H
#define LEETCODE_CPP_Q198_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        if (n == 1)
            return dp[0];

        dp[1] = max(dp[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

#endif //LEETCODE_CPP_Q198_H
