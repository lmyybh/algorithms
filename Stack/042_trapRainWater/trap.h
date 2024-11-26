/*
 * 题目：42. 接雨水
 * 链接：https://leetcode.cn/problems/trapping-rain-water/description/
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

// 解法一：双重遍历，找每根柱子左右侧最高的柱子高度（会超时）
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
int trap_v1(vector<int> &height)
{
    int res = 0;
    for (int i = 1; i < height.size() - 1; ++i)
    {
        // 找到当前柱子左侧最高的柱子
        int left = 0;
        for (int j = i - 1; j >= 0; --j)
        {
            if (left < height[j])
                left = height[j];
        }

        // 找到当前柱子右侧最高的柱子
        int right = 0;
        for (int j = i + 1; j < height.size(); ++j)
        {
            if (right < height[j])
                right = height[j];
        }

        // 计算当前柱子接到的雨水
        int minH = min(left, right);
        res += max(0, minH - height[i]);
    }

    return res;
}

// 解法二：动态规划，使用数组记录每个柱子左右侧最高的柱子高度
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int trap_v2(vector<int> &height)
{
    int n = height.size();

    vector<int> left(n, 0);  // left[i] 表示柱子 i 左侧最高的柱子高度
    vector<int> right(n, 0); // right[i] 表示柱子 i 右侧最高的柱子高度

    // 动态规划，记录最高的柱子高度
    for (int i = 1; i < n; ++i)
        left[i] = max(left[i - 1], height[i - 1]);

    for (int i = n - 2; i >= 0; --i)
        right[i] = max(right[i + 1], height[i + 1]);

    int res = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        // 计算当前柱子接到的雨水
        int minH = min(left[i], right[i]);
        res += max(0, minH - height[i]);
    }

    return res;
}

// 解法三：双指针，从左右向中间聚拢，每次计算较低一侧的接水量
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int trap_v3(vector<int> &height)
{
    int n = height.size();
    int i = 1, j = n - 2; // i 为左指针，j 为右指针
    // left 表示左指针左边最高的柱子高度，right 表示右指针右边最高的柱子高度
    int left = height[0], right = height[n - 1];

    int res = 0;

    while (i <= j)
    {
        // left < right，表示左指针左边最高的柱子高度一定小于右边最高的柱子高度
        // 根据水桶效应，可以直接计算左指针的接水量
        if (left < right)
        {
            res += max(0, left - height[i]);

            // 更新左边最高的柱子高度和左指针
            left = max(left, height[i]);
            ++i;
        }
        else // 右侧同理
        {
            res += max(0, right - height[j]);

            // 更新右边最高的柱子高度和右指针
            right = max(right, height[j]);
            --j;
        }
    }

    return res;
}

// 解法四：单调栈，保持栈内柱子的高度单调递减，每次出栈计算接水量
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int trap_v4(vector<int> &height)
{
    stack<int> stack;
    int res = 0;

    for (int i = 0; i < height.size(); ++i)
    {
        while (!stack.empty() && height[stack.top()] < height[i])
        {
            // 栈顶第二个柱子，栈顶柱子和当前柱子共同用来接水
            int midH = height[stack.top()];
            stack.pop();
            if (stack.empty())
                break;

            int left = stack.top();
            int h = max(0, (min(height[left], height[i]) - midH));
            int w = i - left - 1;
            res += w * h;
        }

        stack.push(i);
    }

    return res;
}