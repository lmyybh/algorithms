/*
 * 题目：17. 电话号码的字母组合
 * 链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include "letterCombinations.h"

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

void Test(vector<string> func(string &), string digits, vector<string> result)
{
    vector<string> res = func(digits);

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
    vector<string> (*func)(string &) = letterCombinations;

    Test(func, "23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    Test(func, "", {});
    Test(func, "2", {"a", "b", "c"});

    return 0;
}
