/*
 * 题目：22. 括号生成
 * 链接：https://leetcode.cn/problems/generate-parentheses/description/
 */

#include <vector>
#include <string>

using namespace std;

// 解法一：回溯
// 时间复杂度：O(4^n/sqrt(n))
// 空间复杂度：O(n)
void generate(vector<string> &res, int &n, string s, int preSum)
{
    if (s.size() == 2 * n)
    {
        res.push_back(s);
        return;
    }

    // 根据左括号的数量，判断下一个字符可以是什么
    vector<char> nextChars;
    if (preSum == 0) // 左边已经完全匹配时，下一个只能是 '('
    {
        nextChars = {'('};
    }
    else if (preSum == 2 * n - s.size()) // 右边必须全部用 ')' 填充时，下一个必须是 ')'
    {
        nextChars = {')'};
    }
    else // 其他情况，左右括号都可
    {
        nextChars = {'(', ')'};
    }

    for (char c : nextChars)
    {
        s.push_back(c);
        generate(res, n, s, preSum + (c == '(' ? 1 : -1));
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    generate(res, n, "", 0);

    return res;
}