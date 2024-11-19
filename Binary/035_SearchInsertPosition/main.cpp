/*
 * 题目：35. 搜索插入位置
 * 链接：https://leetcode.cn/problems/search-insert-position/description/
 */

#include <iostream>
#include "searchInsert.h"

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
    int (*func)(vector<int> &, int) = searchInsert;

    Test(func, {1, 3, 5, 6}, 5, 2);
    Test(func, {1, 3, 5, 6}, 2, 1);
    Test(func, {1, 3, 5, 6}, 7, 4);

    return 0;
}
