/*
 * 题目：3.无重复字符的最长子串
 * 链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 */

#include <iostream>
#include "longestSubstr.cpp"

void Test(int func(string s), string s, int result)
{
    int res = func(s);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(string s) = longestSubstr_v2;

    Test(func, "abcabcbb", 3);
    Test(func, "bbbbb", 1);
    Test(func, "pwwkew", 3);

    return 0;
}
