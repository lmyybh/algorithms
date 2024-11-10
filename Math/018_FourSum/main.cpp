/*
 * 18. 四数之和
 * https://leetcode.cn/problems/4sum/description/
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include "fourSum.h"

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

void Test(vector<vector<int>> func(vector<int> &, int), vector<int> nums, int target, vector<vector<int>> result)
{
    vector<vector<int>> res = func(nums, target);

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
    vector<vector<int>> (*func)(vector<int> &, int) = fourSum;

    Test(func, {1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    Test(func, {2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});
    Test(func, {0}, 0, vector<vector<int>>{});
    Test(func, {-5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5}, 0, {{-5, -4, 4, 5}, {-5, -3, 3, 5}, {-5, -2, 2, 5}, {-5, -2, 3, 4}, {-5, -1, 1, 5}, {-5, -1, 2, 4}, {-5, 0, 0, 5}, {-5, 0, 1, 4}, {-5, 0, 2, 3}, {-4, -3, 2, 5}, {-4, -3, 3, 4}, {-4, -2, 1, 5}, {-4, -2, 2, 4}, {-4, -1, 0, 5}, {-4, -1, 1, 4}, {-4, -1, 2, 3}, {-4, 0, 0, 4}, {-4, 0, 1, 3}, {-3, -2, 0, 5}, {-3, -2, 1, 4}, {-3, -2, 2, 3}, {-3, -1, 0, 4}, {-3, -1, 1, 3}, {-3, 0, 0, 3}, {-3, 0, 1, 2}, {-2, -1, 0, 3}, {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    Test(func, {1, -2, -5, -4, -3, 3, 3, 5}, -11, {{-5, -4, -3, 1}});
    Test(func, {0, 4, -5, 2, -2, 4, 2, -1, 4}, 12, {{0, 4, 4, 4}, {2, 2, 4, 4}});

    return 0;
}
