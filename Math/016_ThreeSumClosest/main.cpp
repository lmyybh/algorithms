/*
 * 16. 最接近的三数之和
 * https://leetcode.cn/problems/3sum-closest/description/
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include "threeSumClosest.h"

using namespace std;

void Test(int func(vector<int> &, int), vector<int> nums, int target, int result)
{
    int res = func(nums, target);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &, int) = threeSumClosest;

    Test(func, {-1, 2, 1, -4}, 1, 2);
    Test(func, {0, 0, 0}, 1, 0);

    return 0;
}
