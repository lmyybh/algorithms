/*
 * 题目：5. 最长回文子串
 * 链接：https://leetcode.cn/problems/longest-palindromic-substring/description/
 */

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// 解法：中心扩展法
// 时间复杂度：O(n2)
// 空间复杂度：O(1)
string longestPalindrome(string s)
{
    // 首尾和每个字符中间都插入 #，
    string s1 = "#";
    for (auto c : s)
    {
        s1 += c;
        s1 += "#";
    }

    string res;

    int n = s1.size();
    for (int i = 0; i < n; ++i)
    {
        // 中心扩展，直到遇见不同的字符停止
        int j = 0;
        for (j = 0; j <= min({i, n - 1 - i}); ++j)
        {
            if (s1[i - j] != s1[i + j])
                break;
        }

        // 保留最长的结果
        if (2 * j - 1 > res.size())
        {
            res = s1.substr(i - j + 1, 2 * j - 1);
        }
    }

    // 删除 #
    res.erase(remove(res.begin(), res.end(), '#'), res.end());

    return res;
}
