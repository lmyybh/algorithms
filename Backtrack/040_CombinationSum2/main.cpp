/*
 * 题目：40. 组合总和 II
 * 链接：https://leetcode.cn/problems/combination-sum-ii/description/
 */

#include <iostream>
#include "combinationSum2.h"
#include "../../utils/str.h"

void Test(vector<vector<int>> func(vector<int> &, int), vector<int> candidates, int target, vector<vector<int>> result)
{
    vector<vector<int>> res = func(candidates, target);

    if (res != result)
    {
        cerr << "result error: " << Vector2dToString(res) << " != " << Vector2dToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<vector<int>> (*func)(vector<int> &, int) = combinationSum2;

    Test(func, {10, 1, 2, 7, 6, 1, 5}, 8, {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}});
    Test(func, {2, 5, 2, 1, 2}, 5, {{1, 2, 2}, {5}});

    return 0;
}
