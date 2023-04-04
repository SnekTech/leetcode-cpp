//
// Created by syf on 2023/4/4.
//

#ifndef LEETCODE_CPP_Q130_H
#define LEETCODE_CPP_Q130_H

#include <vector>

using namespace std;

class Solution {
private:
    int m, n;

    void dfs(vector<vector<char>>& board, int row, int column)
    {
        if (row < 0 || row >= m || column < 0 || column >= n)
            return;
        if (board[row][column] != 'O')
            return;

        board[row][column] = 'A';
        dfs(board, row + 1, column);
        dfs(board, row, column + 1);
        dfs(board, row - 1, column);
        dfs(board, row, column - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++)
        {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

#endif //LEETCODE_CPP_Q130_H
