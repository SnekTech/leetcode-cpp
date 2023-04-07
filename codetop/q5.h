//
// Created by syf on 2023/4/7.
//
#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if ((j - i < 2 || dp[i + 1][j - 1] > 0) && s[i] == s[j])
                    dp[i][j] = j - i + 1;

        int maxLength = 0;
        int maxI = 0, maxJ = 0;

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                if (dp[i][j] >= maxLength)
                {
                    maxLength = dp[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }

        return s.substr(maxI, maxJ - maxI + 1);
    }
};