/*
 * 29. 两数相除
 * https://leetcode.cn/problems/divide-two-integers/description/
 */

#include <iostream>
#include "divide.h"

using namespace std;

void Test(int func(int, int), int dividend, int divisor, int result)
{
    int res = func(dividend, divisor);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(int, int) = divide;

    Test(func, 10, 3, 3);
    Test(func, 7, -3, -2);
    Test(func, -2147483648, 1, -2147483648);
    Test(func, 2147483647, 1, 2147483647);
    Test(func, 1100540749, -1090366779, -1);

    return 0;
}
