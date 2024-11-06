/*
 * 题目：3. 整数反转
 * 链接：https://leetcode.cn/problems/reverse-integer/description/
 */
#include <iostream>
using namespace std;

int reverse(int x)
{
    int res = 0;
    while (x != 0)
    {
        // 超出这一范围时，再添加一位会溢出
        if (res > 214748364 || res < -214748364)
            return 0;

        int n = x % 10;
        res = 10 * res + n;

        x /= 10;
    }

    return res;
}