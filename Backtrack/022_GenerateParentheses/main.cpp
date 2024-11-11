/*
 * 题目：22. 括号生成
 * 链接：https://leetcode.cn/problems/generate-parentheses/description/
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include "generateParentheses.h"

string vectorToString(vector<string> &v)
{
    ostringstream os;
    os << "[";
    for (auto it = v.cbegin(); it != v.cend(); ++it)
    {
        os << *it;
        if (it != v.cend() - 1)
            os << ", ";
    }
    os << "]";

    return os.str();
}

void Test(vector<string> func(int), int n, vector<string> result)
{
    vector<string> res = func(n);

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
    vector<string> (*func)(int) = generateParenthesis;

    Test(func, 3, {"((()))", "(()())", "(())()", "()(())", "()()()"});
    Test(func, 1, {"()"});

    return 0;
}
