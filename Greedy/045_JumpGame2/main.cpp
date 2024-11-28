/*
 * 题目：45. 跳跃游戏 II
 * 链接：https://leetcode.cn/problems/jump-game-ii/description/
 */

#include <iostream>
#include "jump.h"

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
    int (*func)(vector<int> &) = jump;

    Test(func, {2, 3, 1, 1, 4}, 2);
    Test(func, {2, 3, 0, 1, 4}, 2);

    return 0;
}
