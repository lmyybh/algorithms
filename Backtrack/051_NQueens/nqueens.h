/*
 * 题目：51. N 皇后
 * 链接：https://leetcode.cn/problems/n-queens/description/
 */

#include <string>
#include <vector>

using namespace std;

// 解法一：使用二维数组记录棋盘，回溯遍历每一行上满足条件的皇后位置
// 时间复杂度：O(n！)
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

vector<vector<string>> solveNQueens_v1(int n)
{
    vector<vector<string>> result;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    backtrack(board, 0, result);

    return result;
}

// 解法二：使用位运算记录棋盘，回溯遍历每一行上满足条件的皇后位置
// 时间复杂度：O(n!)
// 空间复杂度：O(n)
void backtrack_bit(vector<vector<char>> &board, int row, int columns, int diag1, int diag2, vector<vector<string>> &result)
{
    // row 代表当前要放置第 row 行的皇后
    // columns 中，1 代表当前不可以选择的列，0 代表当前可以选择的列
    // diag1 中，1 代表与之前的皇后左对角线(/)冲突，0 代表不冲突
    // diag2 中，1 代表与之前的皇后右对角线(\)冲突，0 代表不冲突

    // row == n 表示已经填充完毕 n 个皇后，result + 1
    int n = board.size();
    if (row == n)
    {
        result.push_back(rowToString(board));
        return;
    }

    // 在第 row 行中，只能选择 columns, diag1, diag2 三者均为 0 的列，即 (columns | diag1 | diag2) 的低 n 位中为 0 的位置
    // 这里为了方便判断，进行取反，即选择 ~(columns | diag1 | diag2) 的低 n 位中为 1 的位置
    int bits = ~(columns | diag1 | diag2) & ((1 << n) - 1); // 与 ((1 << n) - 1) 进行与运算，可以把高于 n 位的位置都置为 0

    // bits > 0 表示第 row 行存在可以放置皇后的位置
    while (bits > 0)
    {
        int pick = bits & -bits; // x & -x 操作可以只保留最后一位为 1 的位置，相当于挑选 bits 中最后一位为 1 的位置放置皇后

        // 回溯，查找第 row + 1 行皇后的位置
        // 此时，pick 中的 1 代表第 row 行皇后的位置
        // 因此，row + 1 行不再能够选择 pick 中 1 对应的列，因此 columns 更新为 columns | pick
        // row + 1 行不再能够选择 pick 中 1 对应的左对角线，这里可以分三步理解：
        // (1) 假设第 row 行没有放皇后，则第 row + 1 行对应的 diag1 应该更新为 diag1 << 1
        // (2) 第 row 行在 pick 中 1 对应的列放置了皇后，其对应在 row + 1 行的左对角线为 pick << 1 中 1 对应的列
        // (3) 综合考虑 (1) 和 (2)，第 row + 1 行的左对角线应该更新为 (diag1 << 1) | (pick << 1) = (diag1 | pick) << 1
        // 同理，diag2 更新为 (diag2 | pick) >> 1

        int col = __builtin_ctz(pick); // __builtin_ctz 可以返回末尾 0 的个数，对应这里就是指皇后放置的 col
        board[row][col] = 'Q';

        backtrack_bit(board, row + 1, columns | pick, (diag1 | pick) << 1, (diag2 | pick) >> 1, result);
        board[row][col] = '.';

        bits &= bits - 1; // x & (x-1) 操作可以将最后一位为 1 置 0，相当于
    }
}

vector<vector<string>> solveNQueens_v2(int n)
{
    vector<vector<string>> result;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    backtrack_bit(board, 0, 0, 0, 0, result);

    return result;
}