/*
 * 题目：4. 寻找两个正序数组的中位数
 * 链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 */

#include <iostream>
#include "findMedianSortedArrays.h"

void Test(double func(vector<int> &, vector<int> &), vector<int> nums1, vector<int> nums2, double result)
{
    double res = func(nums1, nums2);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    double (*func)(vector<int> &, vector<int> &) = findMedianSortedArrays_v3;

    Test(func, {1, 3}, {2}, 2.0);
    Test(func, {1, 3}, {2, 4}, 2.5);
    Test(func, {2, 2, 4, 4}, {2, 2, 2, 4, 4}, 2.0);

    return 0;
}
