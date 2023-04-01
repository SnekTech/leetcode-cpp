//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q62_H
#define LEETCODE_CPP_Q62_H
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        grid[0][0] = 1;
        for (int j = 1; j < n; j++)
        {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
};
#endif //LEETCODE_CPP_Q62_H
