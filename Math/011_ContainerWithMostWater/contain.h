/*
 * 11. 盛最多水的容器
 * https://leetcode.cn/problems/container-with-most-water/description/
 */

#include <vector>
#include <algorithm>

using namespace std;

// 解法：双指针，贪心算法。从左右向中间收缩，每次收缩较低的一边
//      间距在变小，如果不改变较低的一边，那收缩后面积一定会更小
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int maxArea(vector<int> &height)
{
    auto leftIter = height.cbegin();
    auto rightIter = height.cend() - 1;

    int res = 0;
    while (leftIter < rightIter)
    {
        int area = min({*leftIter, *rightIter}) * (rightIter - leftIter);
        res = max({res, area});

        if (*leftIter <= *rightIter)
            ++leftIter;
        else
            --rightIter;
    }

    return res;
}
