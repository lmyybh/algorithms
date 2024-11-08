/*
 * 题目：14. 最长公共前缀
 * 链接：https://leetcode.cn/problems/longest-common-prefix/description/
 */

#include <iostream>
#include "longestCommonPrefix.h"

void Test(string func(vector<string> &), vector<string> strs, string result)
{
    string res = func(strs);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    string (*func)(vector<string> &) = longestCommonPrefix;

    Test(func, {"flower", "flow", "flight"}, "fl");
    Test(func, {"dog", "racecar", "car"}, "");
}