/*
 * 16. 最接近的三数之和
 * https://leetcode.cn/problems/3sum-closest/description/
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 解法：排序+双指针，选定第一个数和第二个数，双指针遍历其他两数
// 时间复杂度：O(n3)
// 空间复杂度：O(n)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    if (nums.size() < 4)
        return {};

    sort(nums.begin(), nums.end());

    auto sumFunc = [&nums, &target](int i, int j, int m, int n)
    {
        // 避免溢出，转为 long
        return static_cast<long>(nums[i]) + nums[j] + nums[m] + nums[n];
    };

    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 3; ++i)
    {
        // 短路：固定第一个数后，最小组合大于 target，可以不用继续遍历 i, j, m, n，直接跳出
        if (sumFunc(i, i + 1, i + 2, i + 3) > target)
            break;

        // 短路：固定第一个数后，最大组合小于 target，可以不用继续遍历 j, m, n
        if (sumFunc(i, nums.size() - 3, nums.size() - 2, nums.size() - 1) < target)
            continue;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size() - 2; ++j)
        {
            // 短路：最小组合已经大于 target，可以不用遍历 m, n
            if (sumFunc(i, j, j + 1, j + 2) > target)
                continue;

            // 短路：最大组合小于 target，可以不用遍历 m, n
            if (sumFunc(i, j, nums.size() - 2, nums.size() - 1) < target)
                continue;

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int m = j + 1, n = nums.size() - 1;

            while (m < n)
            {
                if (sumFunc(i, j, m, n) < target)
                {
                    ++m;
                    while (m < n && nums[m] == nums[m - 1])
                        ++m;
                }
                else if (sumFunc(i, j, m, n) > target)
                {
                    --n;
                    while (m < n && nums[n] == nums[n + 1])
                        --n;
                }
                else
                {
                    res.push_back({nums[i], nums[j], nums[m], nums[n]});
                    ++m;
                    while (m < n && nums[m] == nums[m - 1])
                        ++m;
                    --n;
                    while (m < n && nums[n] == nums[n + 1])
                        --n;
                }
            }
        }
    }

    return res;
}