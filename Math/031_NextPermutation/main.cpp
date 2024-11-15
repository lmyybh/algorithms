/*
 * 31. 下一个排列
 * https://leetcode.cn/problems/next-permutation/
 */

#include <iostream>
#include <sstream>
#include "nextPermutation.h"
#include "../../utils/str.h"

using namespace std;

void Test(void func(vector<int> &), vector<int> nums, vector<int> result)
{
    func(nums);

    if (nums != result)
    {
        cerr << "result error: " << vectorToString(nums) << " != " << vectorToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    void (*func)(vector<int> &) = nextPermutation;

    Test(func, {1, 2, 3}, {1, 3, 2});
    Test(func, {3, 2, 1}, {1, 2, 3});
    Test(func, {1, 1, 5}, {1, 5, 1});
    Test(func, {2, 3, 1, 3, 3}, {2, 3, 3, 1, 3});

    return 0;
}
