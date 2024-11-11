/*
 * 题目：20. 有效的括号
 * 链接：https://leetcode.cn/problems/valid-parentheses/description/
 */

#include <string>
#include <stack>

using namespace std;

// 解法：栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
bool isValid(string s)
{
    if (s.length() % 2 != 0)
        return false;

    auto match = [](char a, char b)
    {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    };

    stack<char> charStack;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            charStack.push(c);
        else
        {
            if (charStack.empty())
                return false;

            if (!match(charStack.top(), c))
                return false;

            charStack.pop();
        }
    }

    return charStack.empty();
}