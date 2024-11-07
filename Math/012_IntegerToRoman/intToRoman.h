/*
 * 12.整数转罗马数字
 * https://leetcode.cn/problems/integer-to-roman/description/
 */

#include <string>
#include <utility>

using namespace std;

// 解法：模拟，从大到小逐步减
// 时间复杂度：O(1)
// 空间复杂度：O(1)
string intToRoman(int num)
{
    const pair<int, string> symbols[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    string res;
    for (auto &p : symbols)
    {
        while (num >= p.first)
        {
            num -= p.first;
            res += p.second;
        }

        if (num == 0)
            break;
    }

    return res;
}