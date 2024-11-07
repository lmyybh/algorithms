/*
 * 题目：10.正则表达式匹配
 * 链接：https://leetcode.cn/problems/regular-expression-matching/description/
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 解法：动态规划
// 时间复杂度：O(mn)
// 空间复杂度：O(mn)
bool isMatch(string s, string p)
{
    using size_t = string::size_type;

    size_t m = s.size(), n = p.size();
    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));
    dp[0][0] = 1;

    for (size_t i = 0; i < m + 1; ++i)
    {
        for (size_t j = 1; j < n + 1; ++j)
        {
            if (p[j - 1] == '.')
            {
                dp[i][j] = i > 0 && dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                // 题目规定 * 的使用是合法的，因此 * 前面一定有字符，且是 . 或者 a-z

                // 情况一：无需使用 * 匹配字符
                dp[i][j] |= dp[i][j - 2];

                // 情况二：使用 * 匹配一个或多个字符，换个角度讲，就是去掉 s 的一个字符，也可以匹配
                if (p[j - 2] == '.')
                {
                    dp[i][j] |= (i > 0 && dp[i - 1][j]);
                }
                else
                {
                    // 如果 * 前面是 a-z，需要检查字母是否一致
                    dp[i][j] |= (i > 0 && s[i - 1] == p[j - 2] && dp[i - 1][j]);
                }
            }
            else
            {
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
        }
    }

    return dp[m][n];
}