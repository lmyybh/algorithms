/*
 * 12.整数转罗马数字
 * https://leetcode.cn/problems/integer-to-roman/description/
 */

#include <iostream>
#include "intToRoman.h"

using namespace std;

void Test(string func(int), int num, string result)
{
    string res = func(num);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    string (*func)(int) = intToRoman;

    Test(func, 3749, "MMMDCCXLIX");
    Test(func, 58, "LVIII");
    Test(func, 1994, "MCMXCIV");

    return 0;
}
