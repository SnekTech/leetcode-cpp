//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q518_H
#define LEETCODE_CPP_Q518_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++)
            dp[0][j] = j % coins[0] == 0 ? 1 : 0;

        for (int i = 1; i < n; i++)
            for (int j = 0; j <= amount; j++)
                for (int k = 0; k * coins[i] <= j; k++)
                    dp[i][j] += dp[i - 1][j - k * coins[i]];

        return dp[n - 1][amount];
    }
};

#endif //LEETCODE_CPP_Q518_H
