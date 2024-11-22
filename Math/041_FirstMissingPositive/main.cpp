/*
 * 41. 缺失的第一个正数
 * https://leetcode.cn/problems/first-missing-positive/description/
 */

#include <iostream>
#include "first.h"

using namespace std;

void Test(int func(vector<int> &), vector<int> nums, int result)
{
    int res = func(nums);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &) = firstMissingPositive;

    Test(func, {1, 2, 0}, 3);
    Test(func, {3, 4, -1, 1}, 2);
    Test(func, {7, 8, 9, 11, 12}, 1);
    Test(func, {1}, 2);

    return 0;
}
