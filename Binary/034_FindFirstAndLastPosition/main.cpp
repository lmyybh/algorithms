/*
 * 题目：34. 在排序数组中查找元素的第一个和最后一个位置
 * 链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

#include <iostream>
#include "searchRange.h"
#include "../../utils/str.h"

void Test(vector<int> func(vector<int> &, int), vector<int> nums, int target, vector<int> result)
{
    vector<int> res = func(nums, target);

    if (res != result)
    {
        cerr << "result error: " << vectorToString(res) << " != " << vectorToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<int> (*func)(vector<int> &, int) = searchRange;

    Test(func, {5, 7, 7, 8, 8, 10}, 8, {3, 4});
    Test(func, {5, 7, 7, 8, 8, 10}, 6, {-1, -1});
    Test(func, {}, 0, {-1, -1});

    return 0;
}
