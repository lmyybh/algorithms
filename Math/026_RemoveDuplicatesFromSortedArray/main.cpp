/*
 * 26. 删除有序数组中的重复项
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
 */

#include <iostream>
#include "removeDuplicates.h"

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
    int (*func)(vector<int> &) = removeDuplicates;

    Test(func, {1, 1, 2}, 2);
    Test(func, {1, 2, 3}, 3);
    Test(func, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5);

    return 0;
}
