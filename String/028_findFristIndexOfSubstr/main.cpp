/*
 * 题目：28. 找出字符串中第一个匹配项的下标
 * 链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 */

#include <iostream>
#include "findSubstr.h"

void Test(int func(string, string), string s, string p, int result)
{
    int res = func(s, p);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(string, string) = findStr_v1;

    Test(func, "sadbutsad", "sad", 0);
    Test(func, "leetcode", "leeto", -1);
    Test(func, "a", "a", 0);
}