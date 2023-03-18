//
// Created by syf on 2023/3/19.
//

#ifndef LEETCODE_CPP_Q04_H
#define LEETCODE_CPP_Q04_H

#include <vector>
using std::vector;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            int mid = matrix[i][j];
            if (target == mid)
            {
                return true;
            }

            if (target < mid)
            {
                i--;
            }
            else
            {
                j++;
            }
        }

        return false;
    }
};
#endif //LEETCODE_CPP_Q04_H
