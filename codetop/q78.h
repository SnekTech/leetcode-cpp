//
// Created by syf on 2023/4/3.
//

#ifndef LEETCODE_CPP_Q78_H
#define LEETCODE_CPP_Q78_H

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(const vector<int>& nums, int index)
    {
        result.push_back(path);

        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

#endif //LEETCODE_CPP_Q78_H
