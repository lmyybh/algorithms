/*
 * 题目：35. 搜索插入位置
 * 链接：https://leetcode.cn/problems/search-insert-position/description/
 */

#include <vector>

using namespace std;

// 解法：二分法
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}