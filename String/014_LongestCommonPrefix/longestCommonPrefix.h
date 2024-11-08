/*
 * 题目：14. 最长公共前缀
 * 链接：https://leetcode.cn/problems/longest-common-prefix/description/
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 解法：挨个字符比较，直到结束或者遇到不同字符
// 时间复杂度：O(mn)
// 空间复杂度：O(1)
string longestCommonPrefix(vector<string> &strs)
{
    string res;
    string &s = strs[0]; // 题干说了 strs.size() > 0

    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 1; j < strs.size(); ++j)
        {
            if (i >= strs[j].size() || strs[j][i] != s[i])
                return res;
        }
        res += s[i];
    }

    return res;
}