/*
 * 题目：32. 最长有效括号
 * 链接：https://leetcode.cn/problems/longest-valid-parentheses/description/
 */

#include <string>
#include <vector>

using namespace std;

// 解法一：借助栈匹配括号，找最长字串
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int longestValidParentheses_v1(string s)
{
    if (s.empty())
        return 0;

    vector<pair<int, char>> stack;
    stack.push_back(make_pair(-1, 's')); // 插入一个开始标记

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (!stack.empty() && c == ')' && stack.back().second == '(')
            stack.pop_back();
        else
            stack.push_back(make_pair(i, c));
    }
    stack.push_back(make_pair(s.length(), 'e')); // 插入一个结尾标记

    int res = 0;
    for (auto it = stack.cbegin() + 1; it != stack.cend(); ++it)
    {
        res = max({res, it->first - (it - 1)->first - 1}); // 两两做差，得到有效长度，保留最大值
    }

    return res;
}

// 解法二：使用两个常数，记录左括号和右括号数量，相等时即为有效。需要正序遍历和反序遍历各一次
// 时间复杂度：O(n)
// 空间复杂度：O(1)

int longestValidParentheses_v2(string s)
{
    int res = 0;

    // 实现遍历方式
    auto f = [&s, &res](int start, int end, int step, char firstChar)
    {
        int first = 0, second = 0; // 记录两种括号的数量
        for (int i = start; i != end; i += step)
        {
            if (s[i] == firstChar)
            {
                ++first;
            }
            else
            {
                ++second;
                if (first == second) // 二者相等时，记录最大有效长度
                {
                    res = max(res, first + second);
                }
                else if (second > first) // 后者大于前者时，失效，都归 0
                {
                    first = second = 0;
                }
            }
        }
    };

    f(0, s.length(), 1, '(');       // 正向遍历
    f(s.length() - 1, -1, -1, ')'); // 返向遍历

    return res;
}

// 解法三：动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int longestValidParentheses_v3(string s)
{
    if (s.empty())
        return 0;

    vector<int> dp(s.length(), 0); // dp[i] 代表以位置 i 结尾的字符串中，最大有效括号的长度

    int res = 0;
    // 从第二个字符遍历
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == '(')
            dp[i] = 0; // 左括号结尾，不存在有效括号，长度为 0
        else
        {
            // 右括号的前一个为左括号，二者匹配，有效长度 + 2
            if (s[i - 1] == '(')
                dp[i] = i >= 2 ? (dp[i - 2] + 2) : 2;
            else
            {
                // 右括号的前一个为右括号，只有形如 ((...)) 的形式有效
                // 即，前一个右括号结尾存在有效长度，且有效字符串串之前为左括号时，当前右括号结尾存在有效括号
                // s[i - 1 - dp[i - 1]] 表示“前一个右括号的有效字符串”的前一个字符
                if (dp[i - 1] > 0 && i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                {
                    dp[i] = dp[i - 1] + 2; // 长度 + 2

                    // ((...)) 的前一个字符结尾处，可能存在有效长度
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] += dp[i - dp[i - 1] - 2];
                }
            }
        }

        res = max(res, dp[i]);
    }

    return res;
}