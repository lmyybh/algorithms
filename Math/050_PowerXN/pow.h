/*
 * 题目：50. Pow(x, n)
 * 链接：https://leetcode.cn/problems/powx-n/description/
 */

// 解法：递归，快速幂
// 时间复杂度：O(logn)
// 空间复杂度：O(logn)
double myPow(double x, int n)
{
    if (x == 0.0)
        return 0.0;
    else if (x == 1.0)
        return 1.0;

    if (n == 0)
        return 1.0;
    else if (n == 1)
        return x;
    else if (n == -1)
        return 1 / x;

    double y = myPow(x, n / 2);
    double res = y * y;

    if (n % 2 != 0)
    {
        res *= (n < 0) ? (1 / x) : x;
    }

    return res;
}