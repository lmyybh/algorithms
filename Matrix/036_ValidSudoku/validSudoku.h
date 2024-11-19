/*
 * 题目：36. 有效的数独
 * 链接：https://leetcode.cn/problems/valid-sudoku/description/
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

// 解法：遍历，判断行、列、块内是否有重复数字
// 时间复杂度：O(1)
// 空间复杂度：O(1)
bool isValidSudoku(vector<vector<char>> &board)
{
    int rows[9][9] = {};
    int cols[9][9] = {};
    int blocks[9][9] = {};

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            char &c = board[i][j];
            if (c == '.')
                continue;

            int block_id = (i / 3) * 3 + (j / 3);

            int n = c - '1';
            if (rows[i][n] > 0 || cols[j][n] > 0 || blocks[block_id][n] > 0)
                return false;

            ++rows[i][n];
            ++cols[j][n];
            ++blocks[block_id][n];
        }
    }

    return true;
}