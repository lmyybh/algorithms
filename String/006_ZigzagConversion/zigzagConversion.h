/*
 * 题目：6. Z 字形变换
 * 链接：https://leetcode.cn/problems/zigzag-conversion/description/
 */

#include <string>

using namespace std;

// 解法：数学推理，行数变化有周期性
// 时间复杂度：O(n)
// 空间复杂度：O(1)
string convert(string s, int numRows)
{
    if (numRows == 1 || s.size() <= numRows)
        return s;

    string res;
    for (int i = 0; i < numRows; ++i)
    {
        int j = i;
        res += s[j];

        while (j < s.size())
        {
            if (2 * numRows - 2 * i - 2 > 0)
            {
                j += 2 * numRows - 2 * i - 2;

                if (j < s.size())
                    res += s[j];
            }

            if (2 * i > 0)
            {
                j += 2 * i;

                if (j < s.size())
                    res += s[j];
            }
        }
    }

    return res;
}