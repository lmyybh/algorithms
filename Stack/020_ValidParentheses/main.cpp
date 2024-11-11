/*
 * 题目：20. 有效的括号
 * 链接：https://leetcode.cn/problems/valid-parentheses/description/
 */

#include <iostream>
#include "validParentheses.h"

void Test(bool func(string), string s, bool result)
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
    bool (*func)(string s) = isValid;

    Test(func, "()", true);
    Test(func, "()[]{}", true);
    Test(func, "(]", false);
    Test(func, "([])", true);

    return 0;
}
