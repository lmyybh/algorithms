/*
 * 41. 缺失的第一个正数
 * https://leetcode.cn/problems/first-missing-positive/description/
 */

#include <vector>
#include <climits>

using namespace std;

// 解法：原地哈希，首先交换整数 x 到数组中 x-1 位置，随后遍历找到第一个位置不符合的数
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int firstMissingPositive(vector<int> &nums)
{
    int min = INT_MAX;
    for (int n : nums)
    {
        if (n <= 0)
            continue;

        if (n < min)
            min = n;
    }

    // 最小正数是 1，如果不存在，直接返回
    if (min > 1)
        return 1;

    // 问题转换为找 [1, nums.size()] 中第一个没有出现的数字
    // 通过交换位置，按顺序排列数值
    for (int i = 0; i < nums.size(); ++i)
    {
        while (nums[i] != i + 1)
        {
            // 跳过特殊情况
            if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                break;

            // 将当前位置的数 nums[i]，放到 nums[i] - 1 位置
            int idx = nums[i] - 1;
            nums[i] = nums[idx];
            nums[idx] = idx + 1;
        }
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        // 返回第一个位置与数值不符的数
        if (nums[i] != i + 1)
            return i + 1;
    }

    // [1, nums.size()] 都存在，返回 nums.size() + 1
    return nums.size() + 1;
}