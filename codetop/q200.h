//
// Created by syf on 2023/4/4.
//

#ifndef LEETCODE_CPP_Q200_H
#define LEETCODE_CPP_Q200_H

#include <vector>

using namespace std;

class Solution
{
private:
    const vector<vector<int>> neighbors = {
        { -1, 0 },
        { 0,  -1 },
        { 1,  0 },
        { 0,  1 },
    };

    int m, n;
    int result = 0;

    void dfs(vector<vector<char>>& grid, int rowIndex, int columnIndex)
    {
        if (rowIndex < 0 || rowIndex >= m || columnIndex < 0 || columnIndex >= n)
            return;
        if (grid[rowIndex][columnIndex] == '0')
            return;

        grid[rowIndex][columnIndex] = '0';

        for (const auto& neighbor: neighbors)
        {
            int rowOffset = neighbor[0];
            int columnOffset = neighbor[1];
            dfs(grid, rowIndex + rowOffset, columnIndex + columnOffset);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }
};

#endif //LEETCODE_CPP_Q200_H
