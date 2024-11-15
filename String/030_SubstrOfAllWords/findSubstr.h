/*
 * 题目：30. 串联所有单词的子串
 * 链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// 解法：滑动窗口 + 哈希表，通过哈希表记录滑动窗口中单词与给定词组的个数差
// 时间复杂度：O(ls * n) ls 为字符串 s 的长度，n 为单个单词的长度
// 空间复杂度：O(m * n) m 为 words 的个数，n 为单个单词的长度
vector<int> findSubstring(string s, vector<string> &words)
{
    int m = words.size(), n = words[0].length();

    if (s.length() < m * n)
        return {};

    vector<int> res;

    // 存储单词出现次数的差
    unordered_map<string, int> diffMap;

    // i 代表起始位置
    for (int i = 0; i < min(n, static_cast<int>(s.length()) - m * n + 1); ++i)
    {
        // 初始化单词个数
        diffMap.clear();
        for (string &word : words)
        {
            ++diffMap[word];
        }

        for (int j = 0; j <= (s.length() - i) / n - 1; ++j)
        {
            // 新词到字典，计数减一
            string nextWord = s.substr(i + j * n, n);
            if (--diffMap[nextWord] == 0)
            {
                diffMap.erase(nextWord);
            }

            if (j >= m)
            {
                // 之前的单词移出子串，计数加一
                string preWord = s.substr(i + (j - m) * n, n);
                if (++diffMap[preWord] == 0)
                {
                    diffMap.erase(preWord);
                }
            }

            // 比较字典，存储符合条件的结果
            if (j >= m - 1 && diffMap.empty())
            {
                res.emplace_back(i + (j - m + 1) * n);
            };
        }
    }

    return res;
}