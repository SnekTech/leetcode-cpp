//
// Created by syf on 2023/4/21.
//

#pragma once

#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        auto m = nums1.size();
        auto n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = nums1[0] == nums2[0] ? 1 : 0;
        for (int i = 1; i < m; i++)
            dp[i][0] = nums1[i] == nums2[0] ? 1 : 0;
        for (int j = 1; j < n; j++)
            dp[0][j] = nums1[0] == nums2[j] ? 1 : 0;

        int maxLength = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                maxLength = max(maxLength, dp[i][j]);

        return maxLength;
    }
};