/*
 * 题目：33. 搜索旋转排序数组
 * 链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */

#include <iostream>
#include "search.h"

void Test(int func(vector<int> &, int), vector<int> nums, int target, int result)
{
    int res = func(nums, target);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &, int) = search;

    Test(func, {4, 5, 6, 7, 0, 1, 2}, 0, 4);
    Test(func, {4, 5, 6, 7, 0, 1, 2}, 3, -1);
    Test(func, {1}, 0, -1);

    return 0;
}
