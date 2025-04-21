/*
 * 题目：3524. 求出数组的 X 值 I
 * 链接：https://leetcode.cn/problems/find-x-value-of-array-i/description/
 */

#include <iostream>
#include "findx.h"
#include "../../utils/str.h"

void Test(vector<long long> func(vector<int> &, int), vector<int> nums, int k, vector<long long> result)
{
    vector<long long> res = func(nums, k);
    if (res != result)
    {
        cerr << "result error: " << vectorToString(res) << " != " << vectorToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<long long> (*func)(vector<int> &, int) = resultArray_v2;

    Test(func, {1, 2, 3, 4, 5}, 3, {9, 2, 4});
    Test(func, {1, 2, 4, 8, 16, 32}, 4, {18, 1, 2, 0});
    Test(func, {1, 1, 2, 1, 1}, 2, {9, 6});

    return 0;
}