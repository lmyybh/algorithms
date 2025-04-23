#include <iostream>
#include "subarray.h"

void Test(int func(vector<int> &), vector<int> nums, int result)
{
    int res = func(nums);

    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    int (*func)(vector<int> &) = maxSubArray_v3;

    Test(func, {-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    Test(func, {5, 4, -1, 7, 8}, 23);
    Test(func, {1}, 1);
    Test(func, {-1, 0, -2}, 0);

    return 0;
}