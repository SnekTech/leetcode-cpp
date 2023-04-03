//
// Created by syf on 2023/4/3.
//

#ifndef LEETCODE_CPP_Q77_H
#define LEETCODE_CPP_Q77_H

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;
private:
    void backtrack(int n, int k, int start)
    {
        if (current.size() == k)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            current.push_back(i);
            backtrack(n, k, i + 1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || k > n)
            return result;

        backtrack(n, k, 1);
        return result;
    }
};

#endif //LEETCODE_CPP_Q77_H
