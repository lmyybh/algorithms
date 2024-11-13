/*
 * 27. 移除元素
 * https://leetcode.cn/problems/remove-element/
 */

#include <iostream>
#include "removeElement.h"

void Test(int func(vector<int> &, int), vector<int> nums, int val, int result)
{
    int res = func(nums, val);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &, int) = removeElement_v2;

    Test(func, {3, 2, 2, 3}, 3, 2);
    Test(func, {0, 1, 2, 2, 3, 0, 4, 2}, 2, 5);
    Test(func, {1}, 1, 0);
    Test(func, {}, 0, 0);

    return 0;
}
