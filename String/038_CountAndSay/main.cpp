/*
 * 题目：38. 外观数列
 * 链接：https://leetcode.cn/problems/count-and-say/
 */

#include <iostream>
#include "countAndSay.h"

void Test(string func(int), int n, string result)
{
    string res = func(n);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    string (*func)(int) = countAndSay_v2;

    Test(func, 2, "11");
    Test(func, 4, "1211");
    Test(func, 1, "1");

    return 0;
}
