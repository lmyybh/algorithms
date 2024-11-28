/*
 * 题目：44. 通配符匹配
 * 链接：https://leetcode.cn/problems/wildcard-matching/description/
 */

#include <vector>
#include <string>

using namespace std;

// 解法：动态规划，dp[i][j] 表示 s 前 i 个字符 是否能被 p 前 j 个字符 匹配
// 时间复杂度：O(mn)
// 空间复杂度：O(mn)
bool isMatch(string s, string p)
{
    // dp[i][j] 表示 s 前 i 个字符 是否能被 p 前 j 个字符 匹配
    // p[j-1] == 字母 时，dp[i][j] = dp[i-1][j-1] && p[j-1] == s[i-1]
    // p[j-1] == '?' 时，dp[i][j] = dp[i-1][j-1]
    // p[j-1] == '*' 时，可以分为不匹配字符或者匹配字符
    //    - 不匹配字符时：dp[i][j] = dp[i][j-1]
    //    - 匹配字符时，去掉一个字符也能匹配成功：dp[i][j] = dp[i-1][j]

    // 边界条件
    // dp[0][0] = true
    // dp[i][0] = false, i > 0
    int m = s.length(), n = p.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '?')
            {
                dp[i][j] = i > 0 && dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                // 匹配字符或者不匹配字符
                dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && p[j - 1] == s[i - 1]; // 循环中 j > 0
            }
        }
    }

    return dp[m][n];
}