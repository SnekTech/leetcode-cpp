//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q63_H
#define LEETCODE_CPP_Q63_H
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> grid(m, vector<int>(n, 0));

        grid[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[0][j] != 0)
                break;

            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] != 0)
                break;

            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] != 0)
                {
                    grid[i][j] = 0;
                    continue;
                }

                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
};
#endif //LEETCODE_CPP_Q63_H
