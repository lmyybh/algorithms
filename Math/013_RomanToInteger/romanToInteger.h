/*
 * 13.罗马数字转整数
 * https://leetcode.cn/problems/roman-to-integer/description/
 */

#include <string>
#include <unordered_map>

using namespace std;

// 解法：模拟，从左到右依次转为数字，需要处理左边数字比右边数字小的情况
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int romanToInt(string s)
{
    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int res = 0;
    int i = 0;
    while (i < s.size())
    {
        if (i < s.size() - 1 && map[s[i]] < map[s[i + 1]])
        {
            res += map[s[i + 1]] - map[s[i]];
            i += 2;
        }
        else
        {
            res += map[s[i]];
            ++i;
        }
    }

    return res;
}