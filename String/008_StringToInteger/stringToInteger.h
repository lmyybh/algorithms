/*
 * 题目：8.字符串转换整数 (atoi)
 * 链接：https://leetcode.cn/problems/string-to-integer-atoi/description/
 */

#include <iostream>
#include <string>
#include <climits>

using namespace std;

// 解法：按规则判断，注意溢出
// 时间复杂度: O(n)
// 空间复杂度：O(1)
int myAtoi(string s)
{
    int res = 0;
    int sign = 1;
    bool isStart = true;

    for (char c : s)
    {
        // 判断字符是否为数字，不用判断 isStart，因为数字不会导致读取终止
        if (c >= '0' && c <= '9')
        {
            if (isStart)
                isStart = false;

            // 判断溢出
            int n = c - '0';
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && n > -(INT_MIN % 10)))
            {
                return INT_MIN;
            }

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && n > INT_MAX % 10))
            {
                return INT_MAX;
            }

            res = 10 * res + sign * n;
        }

        // 处理前导空格，加号和减号
        if (isStart)
        {
            if (c == ' ')
                continue;
            else if (c == '+')
            {
                sign = 1;
                isStart = false;
            }
            else if (c == '-')
            {
                sign = -1;
                isStart = false;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (c < '0' || c > '9')
                break;
        }
    }

    return res;
}