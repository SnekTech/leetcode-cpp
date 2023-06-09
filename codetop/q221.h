//
// Created by syf on 2023/4/18.
//
#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            maxSide = max(maxSide, dp[0][j]);
        }

        for (int i = 1; i < m; i++)
        {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            maxSide = max(maxSide, dp[i][0]);
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    continue;

                dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }

        return maxSide * maxSide;
    }

    inline int min3(int a, int b, int c)
    {
        return min(min(a, b), c);
    }
};