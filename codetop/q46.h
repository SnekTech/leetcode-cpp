//
// Created by syf on 2023/4/2.
//

#ifndef LEETCODE_CPP_Q46_H
#define LEETCODE_CPP_Q46_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited;

    vector<vector<int>> permute(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 0)
            return result;

        visited.resize(n, false);
        backtrack(nums, 0);

        return result;
    }
private:
    void backtrack(const vector<int>& nums, int index)
    {
        if (index == nums.size())
        {
            vector<int> temp = current;
            result.push_back(std::move(temp));
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                current.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, index + 1);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
};

#endif //LEETCODE_CPP_Q46_H
