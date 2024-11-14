/*
 * 29. 两数相除
 * https://leetcode.cn/problems/divide-two-integers/description/
 */

#include <climits>

// 解法：用减法模拟乘法
int divide(int dividend, int divisor)
{
    // 1. 可能溢出的情况 被除数为 INT_MIN，除数为 -1，结果 -INT_MIN 会溢出
    // 2. 符号问题：统一两个数的符号做计算，最后决定符号。统一为正数可能会溢出，所以统一为负数
    // 3. 快速返回结果：
    //   (1) 被除数为 0 时，结果为 0
    //   (2) 符号统一为负数时，如果 dividend > divisor，结果为 0

    if (dividend == 0)
        return 0;

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    bool isNeg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

    // 转为负数
    if (dividend > 0)
        dividend = -dividend;
    if (divisor > 0)
        divisor = -divisor;

    if (dividend > divisor)
        return 0;

    // 用减法模拟，避免溢出
    int res = 0; // res 保存负数值，避免溢出
    while (dividend <= divisor)
    {
        int b = divisor, n = -1;
        while (dividend - b <= b) // 当 b 翻倍后仍然可以被减，则对 b 翻倍
        {
            b <<= 1; // b 翻倍
            n <<= 1; // n 翻倍
        }
        res += n;
        dividend -= b;
    }

    return isNeg ? res : -res;
}