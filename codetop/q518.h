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
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memo.resize(n, vector<int>(amount + 1, -1));

        int result = dfs(coins, n - 1, amount);
        return result;
    }

    int dfs(vector<int>& coins, int i, int amount)
    {
        int coin = coins[i];
        if (i == 0)
            return amount % coin == 0 ? 1 : 0;
        if (memo[i][amount] != -1)
            return memo[i][amount];

        int plans = 0;
        for (int k = 0; k * coin <= amount; k++)
        {
            plans += dfs(coins, i - 1, amount - k * coin);
        }

        memo[i][amount] = plans;

        return plans;
    }
};

#endif //LEETCODE_CPP_Q518_H
