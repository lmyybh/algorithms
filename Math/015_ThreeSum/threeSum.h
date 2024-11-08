/*
 * 15. 三数之和
 * https://leetcode.cn/problems/3sum/description/
 */

#include <vector>
#include <algorithm>

using namespace std;

// 解法：模拟，从左到右依次转为数字，需要处理左边数字比右边数字小的情况
// 时间复杂度：O(n)
// 空间复杂度：O(1)
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        // 排序后，如果第一个数字大于 0，则和一定大于 0，后续没有可用的组合了
        if (nums[i] > 0)
            break;

        // 为避免结果重复，需要跳过相同的数字
        if ((i > 0 && nums[i] == nums[i - 1]))
            continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0)
            {
                --k;
                while (j < k && nums[k] == nums[k + 1])
                    --k;
            }
            else if (sum < 0)
            {
                ++j;
                while (j < k && nums[j] == nums[j - 1])
                    ++j;
            }
            else
            {
                res.push_back({nums[i], nums[j], nums[k]});

                --k;
                while (j < k && nums[k] == nums[k + 1])
                    --k;

                ++j;
                while (j < k && nums[j] == nums[j - 1])
                    ++j;
            }
        }
    }

    return res;
}