/*
 * 题目：30. 串联所有单词的子串
 * 链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
 */

#include <iostream>
#include <algorithm>
#include "findSubstr.h"
#include "../../utils/str.h"

void Test(vector<int> func(string, vector<string> &), string s, vector<string> words, vector<int> result)
{
    vector<int> res = func(s, words);

    sort(res.begin(), res.end());
    sort(result.begin(), result.end());

    if (res != result)
    {
        cerr << "result error: " << vectorToString(res) << " != " << vectorToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    vector<int> (*func)(string, vector<string> &) = findSubstring;

    Test(func, "barfoothefoobarman", {"foo", "bar"}, {0, 9});
    Test(func, "wordgoodgoodgoodbestword", {"word", "good", "best", "word"}, {});
    Test(func, "barfoofoobarthefoobarman", {"bar", "foo", "the"}, {6, 9, 12});

    return 0;
}