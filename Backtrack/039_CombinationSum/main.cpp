/*
 * 题目：39. 组合总和
 * 链接：https://leetcode.cn/problems/combination-sum/description/
 */

#include <iostream>
#include "combinationSum.h"
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
    vector<vector<int>> (*func)(vector<int> &, int) = combinationSum;

    Test(func, {2, 3, 6, 7}, 7, {{2, 2, 3}, {7}});
    Test(func, {2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}});
    Test(func, {2}, 1, {});

    return 0;
}
