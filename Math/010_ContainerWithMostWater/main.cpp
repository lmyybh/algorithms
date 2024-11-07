/*
 * 11. 盛最多水的容器
 * https://leetcode.cn/problems/container-with-most-water/description/
 */

#include <iostream>
#include "contain.h"

using namespace std;

void Test(int func(vector<int> &), vector<int> height, int result)
{
    int res = func(height);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &) = maxArea;

    Test(func, {1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    Test(func, {1, 1}, 1);

    return 0;
}
