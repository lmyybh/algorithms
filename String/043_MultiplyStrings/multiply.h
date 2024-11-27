/*
 * 题目：43. 字符串相乘
 * 链接：https://leetcode.cn/problems/multiply-strings/description/
 */

#include <vector>
#include <string>

using namespace std;

// 解法：模拟，列竖式，num1 的第 i 位与 num2 的第 j 位相乘，结果位于 i + j 和 i + j + 1 位
// 时间复杂度：O(m*n)
// 空间复杂度：O(m+n)
string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    vector<int> result(num1.length() + num2.length(), 0);
    for (int i = num1.length() - 1; i >= 0; --i)
    {
        int n1 = num1[i] - '0';
        for (int j = num2.length() - 1; j >= 0; --j)
        {
            int n2 = num2[j] - '0';

            int x = result[i + j + 1] + n1 * n2; // 加上当前结果
            result[i + j + 1] = x % 10;          // 低位取个位
            result[i + j] += x / 10;             // 高位取十位
        }
    }

    string res;
    for (int i = 0; i < result.size(); ++i)
    {
        // 跳过前导 0
        if (result[i] == 0 && res.empty())
            continue;

        res += result[i] + '0';
    }

    return res;
}