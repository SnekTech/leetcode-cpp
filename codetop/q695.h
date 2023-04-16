//
// Created by syf on 2023/4/16.
//
#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        m = (int)grid.size();
        n = (int)grid[0].size();

        int maxIsland = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 0)
                    maxIsland = max(maxIsland, dfs(grid, i, j));

        return maxIsland;
    }

private:
    int m;
    int n;
    const int neighbors[4][2] = {
        -1, 0,
        1, 0,
        0, -1,
        0, 1,
    };

    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
        {
            return 0;
        }

        grid[row][col] = 0;

        int area = 0;
        for (auto offset: neighbors)
        {
            area += dfs(grid, row + offset[0], col + offset[1]);
        }

        return area + 1;
    }
};