/*
 * 题目：6. Z 字形变换
 * 链接：https://leetcode.cn/problems/zigzag-conversion/description/
 */

#include <iostream>
#include "zigzagConversion.h"

void Test(string func(string, int), string s, int numRows, string result)
{
    string res = func(s, numRows);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    string (*func)(string, int) = convert;

    Test(func, "PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    Test(func, "PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    Test(func, "A", 1, "A");
    Test(func, "A", 2, "A");

    return 0;
}
