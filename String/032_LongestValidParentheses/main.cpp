/*
 * 题目：32. 最长有效括号
 * 链接：https://leetcode.cn/problems/longest-valid-parentheses/description/
 */

#include <iostream>
#include "longestValidParentheses.h"

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
    int (*func)(string) = longestValidParentheses_v3;

    Test(func, "(()", 2);
    Test(func, ")()())", 4);
    Test(func, "", 0);

    return 0;
}
