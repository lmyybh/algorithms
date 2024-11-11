/*
 * 题目：20. 有效的括号
 * 链接：https://leetcode.cn/problems/valid-parentheses/description/
 */

#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> charStack;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            charStack.push(c);
        else
        {
            switch (c)
            {
            case ')':
                if (!charStack.empty() && charStack.top() == '(')
                    charStack.pop();
                else
                    return false;
                break;
            case '}':
                if (!charStack.empty() && charStack.top() == '{')
                    charStack.pop();
                else
                    return false;
                break;
            case ']':
                if (!charStack.empty() && charStack.top() == '[')
                    charStack.pop();
                else
                    return false;
                break;
            default:
                break;
            }
        }
    }

    return charStack.empty();
}