/*
 * 题目：51. N 皇后
 * 链接：https://leetcode.cn/problems/n-queens/description/
 */

#include <string>
#include <vector>

using namespace std;

// 解法一：使用二维数组记录棋盘，回溯遍历每一行上满足条件的皇后位置
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
bool isValid(vector<vector<char>> &board, int row, int col)
{
    if (board[row][col] == 'Q')
        return false;

    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        // 判断列内是否有皇后
        if (board[row][i] == 'Q')
            return false;

        // 判断行内是否有皇后
        if (board[i][col] == 'Q')
            return false;

        // 判断对角线内是否有皇后
        if ((i - row + col) >= 0 && (i - row + col) < n && board[i][i - row + col] == 'Q')
            return false;
        if ((row + col - i) >= 0 && (row + col - i) < n && board[i][row + col - i] == 'Q')
            return false;
    }

    return true;
}

vector<string> rowToString(const vector<vector<char>> &board)
{
    vector<string> res;
    for (const vector<char> &row : board)
    {
        string rowStr;
        for (char c : row)
        {
            rowStr.push_back(c);
        }
        res.push_back(rowStr);
    }
    return res;
}

void backtrack(vector<vector<char>> &board, int row, vector<vector<string>> &result)
{
    if (row >= board.size())
    {
        result.push_back(rowToString(board));
        return;
    }

    for (int col = 0; col < board.size(); ++col)
    {
        if (isValid(board, row, col))
        {
            board[row][col] = 'Q';
            backtrack(board, row + 1, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    backtrack(board, 0, result);

    return result;
}