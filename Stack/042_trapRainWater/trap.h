/*
 * 题目：42. 接雨水
 * 链接：https://leetcode.cn/problems/trapping-rain-water/description/
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int row_area(vector<int> &height)
{
    int left = -1, area = 0;
    for (int i = 0; i < height.size(); ++i)
    {
        if (height[i] > 0)
        {
            if (left >= 0)
            {
                area += i - left - 1;
            }
            left = i;
        }
    }

    return area;
}

int trap(vector<int> &height)
{
    int maxH = height[0];
    for (auto n : height)
    {
        if (maxH < n)
            maxH = n;
    }

    int res = 0;
    for (int i = 0; i < maxH; ++i)
    {
        if (i > 0)
        {
            for (auto &h : height)
                --h;
        }

        res += row_area(height);
    }

    return res;
}