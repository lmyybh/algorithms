/*
 * 题目：9.回文数
 * 链接：https://leetcode.cn/problems/palindrome-number/
 */

#include <iostream>
#include "isPalindrome.h"

using namespace std;

void Test(bool func(int), int x, bool result)
{
    bool res = func(x);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    bool (*func)(int) = isPalindrome;

    Test(func, 121, true);
    Test(func, 1212, false);
    Test(func, -121, false);
    Test(func, 10, false);
}
