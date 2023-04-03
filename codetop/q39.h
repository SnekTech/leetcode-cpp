//
// Created by syf on 2023/4/3.
//

#ifndef LEETCODE_CPP_Q39_H
#define LEETCODE_CPP_Q39_H

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(const vector<int>& candidates, int target, int startIndex)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++)
        {
            int candidate = candidates[i];
            current.push_back(candidate);
            backtrack(candidates, target - candidate, i);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
};

#endif //LEETCODE_CPP_Q39_H
