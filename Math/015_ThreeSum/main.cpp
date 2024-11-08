/*
 * 15. 三数之和
 * https://leetcode.cn/problems/3sum/description/
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include "threeSum.h"

using namespace std;

void sortVector2d(vector<vector<int>> &vec)
{
    for (auto &v : vec)
    {
        sort(v.begin(), v.end());
    }
    sort(vec.begin(), vec.end());
}

string Vector2dToString(vector<vector<int>> &vec)
{
    ostringstream os;
    os << "[";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    {
        os << "[";
        for (auto cb = (*it).cbegin(); cb != (*it).cend(); ++cb)
        {
            os << *cb;
            if (cb != (*it).cend() - 1)
                os << ", ";
        }
        os << "]";
        if (it != vec.cend() - 1)
            os << ", ";
    }
    os << "]";

    return os.str();
}

void Test(vector<vector<int>> func(vector<int> &), vector<int> nums, vector<vector<int>> result)
{
    vector<vector<int>> res = func(nums);

    // 排序后比较
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
    vector<vector<int>> (*func)(vector<int> &nums) = threeSum;

    Test(func, {-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    Test(func, {0, 1, 1}, {});
    Test(func, {0, 0, 0}, {{0, 0, 0}});
    Test(func, {-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}});

    return 0;
}
