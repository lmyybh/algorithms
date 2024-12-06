/*
 * 题目：49. 字母异位词分组
 * 链接：https://leetcode.cn/problems/group-anagrams/description/
 */

#include <iostream>
#include "group.h"
#include "../../utils/str.h"

void Test(vector<vector<string>> func(vector<string> &), vector<string> strs, vector<vector<string>> result)
{
    vector<vector<string>> res = func(strs);

    sortVector2d(res);
    sortVector2d(result);

    if (res != result)
    {
        cerr << "result error: " << Vector2dToString(res) << " != " << Vector2dToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<vector<string>> (*func)(vector<string> &) = groupAnagrams;

    Test(func, {"eat", "tea", "tan", "ate", "nat", "bat"}, {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}});
    Test(func, {""}, {{""}});

    return 0;
}
