/*
 * 题目：3.无重复字符的最长子串
 * 链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 */

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 解法一：滑动窗口法，借助 map 判断重复字符，并且移动左边界
// 时间复杂度：O(n)
// 空间复杂度: O(1)， 因为 ASCII 字符最多 128 个
int longestSubstr_v1(string s)
{
    unordered_map<char, string::size_type> map;

    string::size_type left = 0, right = 0;
    int res = 0;

    for (right = 0; right < s.size(); ++right)
    {
        if (map.find(s[right]) != map.end())
        {
            left = map[s[right]] + 1;
            // 删除 left 左侧的 map 元素
            for (auto it = map.begin(); it != map.end();)
            {
                if (it->second < left)
                {
                    it = map.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }

        map[s[right]] = right;
        res = max({res, static_cast<int>(right - left + 1)});
    }

    return res;
}

// 解法二：滑动窗口法，与解法一相同，但是不删除 map 中元素，而是比大小
// 时间复杂度：O(n)
// 空间复杂度: O(1)， 因为 ASCII 字符最多 128 个
int longestSubstr_v2(string s)
{
    unordered_map<char, string::size_type> map;

    string::size_type left = 0, right = 0;
    int res = 0;

    for (right = 0; right < s.size(); ++right)
    {
        if (map.find(s[right]) != map.end())
        {
            // 如果重复字符在 left 左侧，无须更新 left
            left = max({left, map[s[right]] + 1});
        }

        map[s[right]] = right;
        res = max({res, static_cast<int>(right - left + 1)});
    }

    return res;
}