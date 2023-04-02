//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q131_H
#define LEETCODE_CPP_Q131_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string originS;
    size_t n;
    vector<vector<string>> result;
    vector<string> current;

    vector<vector<string>> partition(string s) {
        if (s == "")
            return result;
        originS = s;
        n = s.size();

        dfs(0);

        return result;
    }

private:
    void dfs(int index)
    {
        if (index == n)
        {
            vector<string> temp(current);
            result.push_back(std::move(temp));
            return;
        }

        for (int i = index; i < n; i++)
        {
            int subLength = i - index + 1;
            const string& subStr = originS.substr(index, subLength);
            if (IsPalindromic(subStr))
            {
                current.push_back(subStr);
                dfs(index + subLength);
                current.erase(current.end() - 1);
            }
        }
    }

    static bool IsPalindromic(const string& s)
    {
        if (s.empty())
            return true;

        size_t left = 0, right = s.size() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};

#endif //LEETCODE_CPP_Q131_H
