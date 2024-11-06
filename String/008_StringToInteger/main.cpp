/*
 * 题目：8.字符串转换整数 (atoi)
 * 链接：https://leetcode.cn/problems/string-to-integer-atoi/description/
 */

#include <iostream>
#include "stringToInteger.h"

void Test(int func(string), string s, int result)
{
    int res = func(s);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(string) = myAtoi;

    Test(func, "42", 42);
    Test(func, "-042", -42);
    Test(func, "1337c0d3", 1337);
    Test(func, "0-1", 0);
    Test(func, "words and 987", 0);
    Test(func, "-2147483649", INT_MIN);
    Test(func, "2147483649", INT_MAX);
}