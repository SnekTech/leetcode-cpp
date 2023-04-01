//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q91_H
#define LEETCODE_CPP_Q91_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            char c = s.at(i - 1);
            if (c != '0')
            {
                dp[i] += dp[i - 1];
            }

            if (i > 1)
            {
                char prevC = s.at(i - 2);
                if (prevC != '0' && (prevC - '0') * 10 + c - '0' <= 26)
                {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
};

#endif //LEETCODE_CPP_Q91_H
