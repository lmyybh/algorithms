/*
 * 题目：46. 全排列
 * 链接：https://leetcode.cn/problems/permutations/description/
 */

#include <iostream>
#include <algorithm>
#include "permute.h"
#include "../../utils/str.h"

void Test(vector<vector<int>> func(vector<int> &), vector<int> nums, vector<vector<int>> result)
{
    vector<vector<int>> res = func(nums);

    sort(res.begin(), res.end());
    sort(result.begin(), result.end());

    if (res != result)
    {
        cerr << "result error: " << Vector2dToString(res) << " != " << Vector2dToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<vector<int>> (*func)(vector<int> &) = permute;

    Test(func, {1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    Test(func, {0, 1}, {{0, 1}, {1, 0}});
    Test(func, {1}, {{1}});

    return 0;
}
