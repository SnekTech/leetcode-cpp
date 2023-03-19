//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q3_H
#define LEETCODE_CPP_Q3_H

#include <string>
#include <unordered_set>

using std::string;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0) return 0;

        std::unordered_set<char> set;

        int maxStr = 0;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            while (set.find(s[i]) != set.end())
            {
                set.erase(s[left]);
                left++;
            }

            maxStr = std::max(maxStr, i - left + 1);
            set.insert(s[i]);
        }

        return maxStr;
    }
};

#endif //LEETCODE_CPP_Q3_H
