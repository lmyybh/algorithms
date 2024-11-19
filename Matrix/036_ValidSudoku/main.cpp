/*
 * 题目：36. 有效的数独
 * 链接：https://leetcode.cn/problems/valid-sudoku/description/
 */

#include <iostream>
#include "validSudoku.h"

void Test(bool func(vector<vector<char>> &), vector<vector<char>> board, bool result)
{
    bool res = func(board);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    bool (*func)(vector<vector<char>> &) = isValidSudoku;

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Test(func, board, true);

    board[0][0] = '8';
    Test(func, board, false);

    return 0;
}
