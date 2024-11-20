/*
 * 题目：37. 解数独
 * 链接：https://leetcode.cn/problems/sudoku-solver/description/
 */

#include <vector>

using namespace std;

// 解法：回溯，在每一个空格上，回溯遍历每个合法的数字
// 时间复杂度：O(9^(9*9)) 复杂度上界，最多有 9*9 个格子，每个格子可以填入 9 个数之一
// 空间复杂度：O(9^(9*9))

// 判断在 (row, col) 填入数字 val 后，数独是否合法
bool isValid(vector<vector<char>> &board, int row, int col, int val)
{
    int blockRow = (row / 3) * 3; // 所在块的左上角元素的行
    int blockCol = (col / 3) * 3; // 所在块的左上角元素的列

    for (int i = 0; i < board.size(); ++i)
    {
        if (board[row][i] == val) // 判断行内是否有重复数字
            return false;
        if (board[i][col] == val) // 判断列内是否有重复数字
            return false;
        if (board[blockRow + i / 3][blockCol + i % 3] == val) // 判断块内是否有重复数字
            return false;
    }

    return true;
}

// 回溯遍历
bool backtrack(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] != '.')
                continue;

            for (char c = '1'; c <= '9'; ++c)
            {
                if (isValid(board, i, j, c))
                {
                    // 填入合法的数字
                    board[i][j] = c;

                    // 继续回溯，如果得到有效解，返回 true
                    if (backtrack(board))
                        return true;
                }
            }

            // 所有后续回溯都不合法，还原为空，返回 false
            board[i][j] = '.';
            return false;
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    backtrack(board);
}