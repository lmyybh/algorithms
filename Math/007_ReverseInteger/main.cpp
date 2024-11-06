/*
 * 题目：3. 整数反转
 * 链接：https://leetcode.cn/problems/reverse-integer/description/
 */

#include <iostream>
#include "reverseInteger.h"

void Test(int func(int x), int x, int result)
{
    int res = func(x);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(int s) = reverse;

    Test(func, 123, 321);
    Test(func, -147, -741);

    return 0;
}
