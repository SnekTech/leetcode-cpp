//
// Created by syf on 2023/4/10.
//
#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<int> dp(n, 0);
        dp[0] = prices[0];

        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[i - 1], prices[i]);
            profit = max(profit, prices[i] - dp[i]);
        }

        return profit;
    }
};