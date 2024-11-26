/*
 * 题目：42. 接雨水
 * 链接：https://leetcode.cn/problems/trapping-rain-water/description/
 */

#include <iostream>
#include "trap.h"

void Test(int func(vector<int> &), vector<int> height, int result)
{
    int res = func(height);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &) = trap_v4;

    Test(func, {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    Test(func, {4, 2, 0, 3, 2, 5}, 9);

    return 0;
}
