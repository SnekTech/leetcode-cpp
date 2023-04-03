//
// Created by syf on 2023/4/3.
//

#ifndef LEETCODE_CPP_Q216_H
#define LEETCODE_CPP_Q216_H

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int k, int target, int start)
    {
        if (target < 0 || path.size() > k)
            return;
        if (target == 0 && path.size() == k)
        {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            backtrack(k, target - i, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return result;
    }
};

#endif //LEETCODE_CPP_Q216_H
