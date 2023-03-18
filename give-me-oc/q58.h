//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q58_H
#define LEETCODE_CPP_Q58_H

#include <string>

using std::string;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string doubleString = s + s;
        return doubleString.substr(n, s.size());
    }
};

#endif //LEETCODE_CPP_Q58_H
