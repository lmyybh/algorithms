/*
 * 13.罗马数字转整数
 * https://leetcode.cn/problems/roman-to-integer/description/
 */

#include <iostream>
#include "romanToInteger.h"

using namespace std;

void Test(int func(string), string s, int result)
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
    int (*func)(string) = romanToInt;

    Test(func, "MMMDCCXLIX", 3749);
    Test(func, "LVIII", 58);
    Test(func, "MCMXCIV", 1994);

    return 0;
}
