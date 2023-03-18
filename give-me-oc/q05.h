//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q05_H
#define LEETCODE_CPP_Q05_H

#include <string>

using std::string;

class Solution {
public:
    string replaceSpace(string s) {
        string result;
        for (char c : s)
        {
            if (c == ' ')
            {
                result += "%20";
            }
            else {
                result += c;
            }
        }

        return result;
    }
};

#endif //LEETCODE_CPP_Q05_H
