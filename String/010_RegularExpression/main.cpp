/*
 * 题目：10.正则表达式匹配
 * 链接：https://leetcode.cn/problems/regular-expression-matching/description/
 */

#include <iostream>
#include "isMatch.h"

void Test(bool func(string, string), string s, string p, bool result)
{
    bool res = func(s, p);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    bool (*func)(string, string) = isMatch;

    Test(func, "aa", "a", false);
    Test(func, "aa", "a*", true);
    Test(func, "mississippi", "mis*is*p*.", false);
    Test(func, "aab", "c*a*b", true);
    Test(func, "aaa", "ab*a*c*a", true);
}