/*
 * 题目：34. 在排序数组中查找元素的第一个和最后一个位置
 * 链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

#include <vector>

using namespace std;

// 解法：二分法，查找两次，一次找左边界，一次找右边界。重点在于 nums[mid] == target 时的边界处理
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
vector<int> searchRange(vector<int> &nums, int target)
{
    int first = -1, last = -1;

    // 找左边界
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] >= target)
        {
            right = mid - 1;
            // 相等时，记录位置
            if (nums[mid] == target)
                first = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    // 找右边界
    left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] <= target)
        {
            left = mid + 1;
            // 相等时，记录位置
            if (nums[mid] == target)
                last = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    return {first, last};
}