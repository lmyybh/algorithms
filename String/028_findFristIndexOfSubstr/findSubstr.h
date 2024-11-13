/*
 * 题目：28. 找出字符串中第一个匹配项的下标
 * 链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 */

#include <string>

using namespace std;

// 解法一：暴力匹配
// 时间复杂度：O(mn)
// 空间复杂度：O(1)
int findStr_v1(string haystack, string needle)
{
    int m = haystack.length(), n = needle.length();

    if (m < n)
        return -1;

    auto isEqual = [&](int idx)
    {
        for (int i = 0; i < n; ++i)
        {
            if (haystack[idx + i] != needle[i])
                return false;
        }
        return true;
    };

    for (int i = 0; i <= m - n; ++i)
    {
        if (isEqual(i))
            return i;
    }

    return -1;
}