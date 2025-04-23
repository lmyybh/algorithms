/*
 * 题目：51. N 皇后
 * 链接：https://leetcode.cn/problems/n-queens/description/
 */

#include <iostream>
#include <algorithm>
#include "nqueens.h"
#include "../../utils/str.h"

void Test(vector<vector<string>> func(int), int n, vector<vector<string>> result)
{
    vector<vector<string>> res = func(n);

    if (res != result)
    {
        cerr << "result error: " << Vector2dToString(res) << " != " << Vector2dToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<vector<string>> (*func)(int) = solveNQueens_v2;

    Test(func, 4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    Test(func, 1, {{"Q"}});

    return 0;
}
