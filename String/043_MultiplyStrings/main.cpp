/*
 * 题目：43. 字符串相乘
 * 链接：https://leetcode.cn/problems/multiply-strings/description/
 */

#include <iostream>
#include "multiply.h"

void Test(string func(string, string), string num1, string num2, string result)
{
    string res = func(num1, num2);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    string (*func)(string, string) = multiply;

    Test(func, "2", "3", "6");
    Test(func, "123", "456", "56088");

    return 0;
}
