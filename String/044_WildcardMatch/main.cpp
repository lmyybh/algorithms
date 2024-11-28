/*
 * 题目：44. 通配符匹配
 * 链接：https://leetcode.cn/problems/wildcard-matching/description/
 */

#include <iostream>
#include "match.h"

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
    Test(func, "aa", "*", true);
    Test(func, "cb", "?a", false);
    Test(func, "aabc", "a*", true);
    Test(func, "aabc", "a*b", false);

    return 0;
}
