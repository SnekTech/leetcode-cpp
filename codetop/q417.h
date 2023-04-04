//
// Created by syf on 2023/4/4.
//

#ifndef LEETCODE_CPP_Q417_H
#define LEETCODE_CPP_Q417_H

#include <vector>
#include <array>

using namespace std;

class Solution
{
private:
    int m, n;
    using Offset = array<int, 2>;
    const array<Offset, 4> neighbors = {{
                                            { -1, 0 },
                                            { 0, -1 },
                                            { 1, 0 },
                                            { 0, 1 }
                                        }};
    vector<vector<int>> result;

    using Ocean = vector<vector<bool>>;

    void dfs(vector<vector<int>>& heights, Ocean& ocean, int row, int col, int lastHeight)
    {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return;
        if (ocean[row][col])
            return;
        int height = heights[row][col];
        if (height < lastHeight)
            return;

        ocean[row][col] = true;

        for (auto& neighbor : neighbors)
        {
            int rowOffset = neighbor[0];
            int colOffset = neighbor[1];
            dfs(heights, ocean, row + rowOffset, col + colOffset, height);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        m = heights.size();
        if (m == 0)
            return result;
        n = heights[0].size();
        const int minHeight = 0;
        Ocean pacific(m, vector<bool>(n, false));
        Ocean atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0, minHeight);
        for (int j = 1; j < n; j++)
            dfs(heights, pacific, 0, j, minHeight);
        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1, minHeight);
        for (int j = 0; j < n - 1; j++)
            dfs(heights, atlantic, m - 1, j, minHeight);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    vector<int> cell = {i, j};
                    result.emplace_back(std::move(cell));
                }
            }

        return result;
    }
};

#endif //LEETCODE_CPP_Q417_H
