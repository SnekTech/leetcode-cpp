//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q93_H
#define LEETCODE_CPP_Q93_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        ipStr = s;
        n = ipStr.size();
        result.clear();

        dfs(0, 0, "");

        return result;
    }

private:
    void dfs(int charIndex, int segmentIndex, const string& prev)
    {
        if (segmentIndex == 4)
        {
            if (charIndex == n)
            {
                string trimmed(prev.substr(0, prev.size() - 1));
                result.push_back(std::move(trimmed));
            }
            return;
        }

        for (int ipLength = 1; ipLength <= 3; ipLength++)
        {
            if (isValidIP(charIndex, ipLength))
            {
                string address = prev + ipStr.substr(charIndex, ipLength) + ".";
                dfs(charIndex + ipLength, segmentIndex + 1, address);
            }
        }
    }

    bool isValidIP(int start, int length)
    {
        if (ipStr[start] == '0' && length > 1)
            return false;

        int ip = 0;
        int end = start + length;
        for (int i = start; i < end; i++)
        {
            ip = ip * 10 + ipStr[i] - '0';
        }

        return ip >= 0 && ip <= 255;
    }

private:
    vector<string> result;
    string ipStr;
    int n;

};

#endif //LEETCODE_CPP_Q93_H
