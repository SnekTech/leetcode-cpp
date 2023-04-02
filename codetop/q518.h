//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q518_H
#define LEETCODE_CPP_Q518_H

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
#endif //LEETCODE_CPP_Q518_H
