/*
 * 题目：50. Pow(x, n)
 * 链接：https://leetcode.cn/problems/powx-n/description/
 */

#include <iostream>
#include "pow.h"

using namespace std;

void Test(double func(double, int), double x, int n, double result)
{
    double res = func(x, n);

    // 精度问题，需要比较差
    if (abs(res - result) > 1e-8)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    double (*func)(double, int) = myPow;

    Test(func, 2.0, 10, 1024.0);
    Test(func, 2.1, 3, 9.26100);
    Test(func, 2.0, -2, 0.25);
    Test(func, 1.0, -2147483648, 1.0);

    return 0;
}
