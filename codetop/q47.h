//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q47_H
#define LEETCODE_CPP_Q47_H

#include <vector>
#include <iostream>
#include "Common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return result;

        visited.resize(n, false);
        std::sort(nums.begin(), nums.end());

        backtrack(nums, 0);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, int index)
    {
        if (index == nums.size())
        {
            result.emplace_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
                continue;

            current.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, index + 1);
            visited[i] = false;
            current.pop_back();
        }
    }
};

#endif //LEETCODE_CPP_Q47_H
