//
// Created by syf on 2023/4/3.
//

#ifndef LEETCODE_CPP_Q90_H
#define LEETCODE_CPP_Q90_H

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(const vector<int>& nums, int startIndex)
    {
        result.push_back(path);

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }
};

#endif //LEETCODE_CPP_Q90_H
