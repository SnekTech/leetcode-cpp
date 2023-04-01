//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q343_H
#define LEETCODE_CPP_Q343_H
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> memo;
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max3(dp[i], j * (i - j), j * dp[i - j]);
            }
        }

        return dp[n];
    }

    int breakInt(int x)
    {
        if (memo.find(x) != memo.cend())
            return memo[x];

        int maxProduct = 0;
        for (int i = 1; i < x; i++)
        {
            maxProduct = max3(maxProduct, i * (x - i), i * breakInt(x - i));
        }

        memo[x] = maxProduct;
        return maxProduct;
    }

    static int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }
};

#endif //LEETCODE_CPP_Q343_H
