/*
 * 题目：38. 外观数列
 * 链接：https://leetcode.cn/problems/count-and-say/
 */

#include <string>

using namespace std;

// 解法一：递归
// 时间复杂度：O(n*m) m 为生成字符串最大长度
// 空间复杂度：O(m)
string rle(string s)
{
    string res;
    char cur = '.';
    int count = 0;
    for (char &c : s)
    {
        if (c == cur)
            ++count;
        else
        {
            if (cur != '.')
                res += to_string(count) + cur;

            cur = c;
            count = 1;
        }
    }

    if (cur != '.')
        res += to_string(count) + cur;

    return res;
}

string countAndSay_v1(int n)
{
    if (n == 1)
        return "1";

    return rle(countAndSay_v1(n - 1));
}

// 解法二：迭代
// 时间复杂度：O(n*m) m 为生成字符串最大长度
// 空间复杂度：O(m)
string countAndSay_v2(int n)
{

    if (n == 1)
        return "1";

    string preStr = "1", res;
    for (int i = 2; i <= n; ++i)
    {
        char cur = '.';
        int count = 0;
        for (char &c : preStr)
        {
            if (c == cur)
                ++count;
            else
            {
                if (cur != '.')
                    res += to_string(count) + cur;

                cur = c;
                count = 1;
            }
        }

        if (cur != '.')
            res += to_string(count) + cur;

        preStr = res;
        res = "";
    }

    return preStr;
}