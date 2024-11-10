/*
 * 16. 最接近的三数之和
 * https://leetcode.cn/problems/3sum-closest/description/
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 解法：排序+双指针，选定第一个数，双指针遍历其他两数
// 时间复杂度：O(n2)
// 空间复杂度：O(1)
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX, res = 0, sum = 0;

    auto updateRes = [&]()
    {
        if (abs(sum - target) < min_diff)
        {
            res = sum;
            min_diff = abs(sum - target);
        }
    };

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        // 为避免结果重复，需要跳过相同的数字
        if ((i > 0 && nums[i] == nums[i - 1]))
            continue;

        // 最小的组合已经大于 target，则不需要继续遍历了
        sum = nums[i] + nums[i + 1] + nums[i + 2];
        if (sum > target)
        {
            updateRes();
            continue;
        }

        // 最大的组合小于 target，也不需要继续遍历
        sum = nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1];
        if (sum < target)
        {
            updateRes();
            continue;
        }

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
                return target;

            updateRes();

            if (sum > target)
            {
                --k;
                while (j < k && nums[k] == nums[k + 1])
                    --k;
            }
            else
            {
                ++j;
                while (j < k && nums[j] == nums[j - 1])
                    ++j;
            }
        }
    }

    return res;
}