/*
 * 题目：49. 字母异位词分组
 * 链接：https://leetcode.cn/problems/group-anagrams/description/
 */

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

// 解法：对字符串的字母计数，计数结果一致的为异位词
// 时间复杂度：O(n*k)
// 空间复杂度：O(n*k)
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<int> flag(26, 0);

    map<vector<int>, vector<string>> map;

    for (string &s : strs)
    {
        std::fill(flag.begin(), flag.end(), 0);
        for (char c : s)
        {
            ++flag[c - 'a'];
        }

        map[flag].push_back(s);
    }

    vector<vector<string>> res;
    for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        res.emplace_back(std::move(iter->second));
    }

    return res;
}
