//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q279_H
#define LEETCODE_CPP_Q279_H
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int minSq = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                minSq = min(minSq, 1 + dp[i - j * j]);
            }

            dp[i] = minSq;
        }

        return dp[n];
    }
};

#endif //LEETCODE_CPP_Q279_H
