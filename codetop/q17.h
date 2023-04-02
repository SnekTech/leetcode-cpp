//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q17_H
#define LEETCODE_CPP_Q17_H

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> lettersByIndex = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> combinations;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return combinations;
        dfs(0, "", digits);
        return combinations;
    }
private:
    void dfs(int index, const string& prevS, const string& digits)
    {
        if (index == digits.size())
        {
            combinations.push_back(prevS);
            return;
        }

        int charIndex = digits[index] - '0';
        string letters = lettersByIndex[charIndex];
        for (int i = 0; i < letters.size(); ++i)
        {
            dfs(index + 1, prevS + letters[i], digits);
        }
    }
};

#endif //LEETCODE_CPP_Q17_H
