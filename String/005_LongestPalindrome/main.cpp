/*
 * 题目：5. 最长回文子串
 * 链接：https://leetcode.cn/problems/longest-palindromic-substring/description/
 */

#include <iostream>
#include "longestPalindrome.cpp"

void Test(string func(string s), string s, string result)
{
    string res = func(s);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    string (*func)(string s) = longestPalindrome;

    Test(func, "babad", "bab");
    Test(func, "cbbd", "bb");

    return 0;
}
