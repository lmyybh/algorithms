/*
 * 题目：17. 电话号码的字母组合
 * 链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 解法：回溯
// 时间复杂度：O(3^m * 4^n)
// 空间复杂度：O(m+n)
void backtrack(const unordered_map<char, string> &map, string &digits, int i, string s, vector<string> &res)
{
    if (i == digits.length())
    {
        res.push_back(s);
        return;
    }

    for (char c : map.at(digits[i]))
    {
        s.push_back(c);
        backtrack(map, digits, i + 1, s, res);
        s.pop_back();
    }
}

vector<string> letterCombinations(string &digits)
{
    if (digits.empty())
        return {};

    const unordered_map<char, string> map{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> res;
    backtrack(map, digits, 0, "", res);

    return res;
}
