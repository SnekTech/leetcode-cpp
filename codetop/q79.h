//
// Created by syf on 2023/4/3.
//

#ifndef LEETCODE_CPP_Q79_H
#define LEETCODE_CPP_Q79_H

#include <vector>
#include <string>
#include <memory>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    string target;
    string path;

    bool backtrack(const vector<vector<char>>& board, int rowIndex, int columnIndex, int charIndex)
    {
        if (charIndex == target.size())
        {
            return true;
        }
        if (rowIndex < 0 || rowIndex >= m || columnIndex < 0 || columnIndex >= n)
            return false;
        if (visited[rowIndex][columnIndex])
            return false;

        char c = board[rowIndex][columnIndex];
        if (c != target[charIndex])
            return false;

        visited[rowIndex][columnIndex] = true;
        path += c;
        bool up = backtrack(board, rowIndex - 1, columnIndex, charIndex + 1);
        if (up)
            return true;
        bool left = backtrack(board, rowIndex, columnIndex - 1, charIndex + 1);
        if (left)
            return true;
        bool down = backtrack(board, rowIndex + 1, columnIndex, charIndex + 1);
        if (down)
            return true;
        bool right = backtrack(board, rowIndex, columnIndex + 1, charIndex + 1);
        if (right)
            return true;

        path.pop_back();
        visited[rowIndex][columnIndex] = false;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        target = std::move(word);
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            visited.emplace_back(n, false);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool found = backtrack(board, i, j, 0);
                if (found)
                    return true;
            }
        }

        return false;
    }
};

#endif //LEETCODE_CPP_Q79_H
