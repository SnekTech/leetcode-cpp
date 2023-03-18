//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q03_H
#define LEETCODE_CPP_Q03_H

#include <vector>
using std::vector;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> set(n, false);

        for (int x : nums)
        {
            if (set[x]) return x;

            set[x] = true;
        }

        return -1;
    }
};

#endif //LEETCODE_CPP_Q03_H
