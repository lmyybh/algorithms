/*
 * 题目：33. 搜索旋转排序数组
 * 链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */

#include <vector>

using namespace std;

// 解法：二分法，先判断哪半边区间有序，再判断 target 是否在有序区间内
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid])
        { // 左半区间有序
            if (target >= nums[left] && target < nums[mid])
            { // target 落在左半区间
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        { // 右半区间有序
            if (target > nums[mid] && target <= nums[right])
            { // target 落在右半区间
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}