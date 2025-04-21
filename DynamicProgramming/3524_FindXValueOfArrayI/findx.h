/*
 * 题目：3524. 求出数组的 X 值 I
 * 链接：https://leetcode.cn/problems/find-x-value-of-array-i/description/
 */

#include <vector>

using namespace std;

// 解法一：动态规划, 依据以第 i 个数结尾的子数组的 X 值，推到以第 i+1 个数结尾的子数组的 X 值
// 时间复杂度：O(nk)
// 空间复杂度：O(nk)
vector<long long> resultArray_v1(vector<int> &nums, int k)
{
    vector<long long> result(k);

    int n = nums.size();

    // dp[i][j] 表示以第 i 个数 (对应下标 i-1) 结尾的子数组，余数为 j 的个数
    vector<vector<long long>> dp(n + 1, vector<long long>(k));

    // 思路：已知 dp[i][j] 对应余数为 j，当下一个数为 nums[i] 时，余数变为 j * nums[j] % k 。因此，
    // dp[i+1][j * nums[j] % k] 可以新增 dp[i][j] 个数量，表示为 dp[i + 1][j * nums[i] % k] += dp[i][j]
    // 其中, dp[0][j] = 0，即空数组对应的每个余数的个数都是 0

    for (int i = 0; i < n; ++i)
    {
        // 为避免后续 j * nums[i] % k 溢出，预先计算余数 v, 后续使用 j * v % k
        int v = nums[i] % k;

        // 当子数组只包括第 i+1 个元素时，其对应的余数个数为 1
        dp[i + 1][v] = 1;

        // 当子数组包括前一个元素时，新增计算后的余数个数
        for (int j = 0; j < k; ++j)
        {
            dp[i + 1][j * v % k] += dp[i][j];
        }

        // 更新结果数组
        for (int j = 0; j < k; ++j)
        {
            result[j] += dp[i + 1][j];
        }
    }

    return result;
}

// 解法二：动态规划, 思路与解法一相同，因为 dp[i+1] 只与 dp[i] 有关，因此可以进一步优化空间
// 时间复杂度：O(nk)
// 空间复杂度：O(k)
vector<long long> resultArray_v2(vector<int> &nums, int k)
{
    vector<long long> result(k);

    int n = nums.size();

    // dp[j] 表示余数为 j 的个数
    vector<long long> dp(k);

    // 思路：已知 dp[i][j] 对应余数为 j，当下一个数为 nums[i] 时，余数变为 j * nums[j] % k 。因此，
    // dp[i+1][j * nums[j] % k] 可以新增 dp[i][j] 个数量，表示为 dp[i + 1][j * nums[i] % k] += dp[i][j]
    // 其中, dp[0][j] = 0，即空数组对应的每个余数的个数都是 0

    for (int i = 0; i < n; ++i)
    {
        // 为避免后续 j * nums[i] % k 溢出，预先计算余数 v, 后续使用 j * v % k
        int v = nums[i] % k;

        // 使用临时变量记录下一个子数组的余数个数，当子数组只包括第 i+1 个元素时，其对应的余数个数为 1
        vector<long long> next_dp(k);
        next_dp[v] = 1;

        // 当子数组包括前一个元素时，新增计算后的余数个数
        for (int j = 0; j < k; ++j)
        {
            next_dp[j * v % k] += dp[j];
        }

        // 更新 dp
        dp = move(next_dp);

        // 更新结果数组
        for (int j = 0; j < k; ++j)
        {
            result[j] += dp[j];
        }
    }

    return result;
}