#include <vector>

using namespace std;

// 解法一：动态规划，dp[i] 代表以 nums[i] 结尾的最大连续子数组和, 满足 dp[i] = max(dp[i-1] + nums[i], nums[i])
// 时间复杂度: O(n)
// 空间复杂度: O(n)
int maxSubArray_v1(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);

    dp[0] = nums[0];
    int result = dp[0];

    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        result = max(result, dp[i]);
    }

    return result;
}

// 解法二：动态规划，空间优化。由于 dp[i] 只与 dp[i-1] 有关，因此可以只用一个变量 dp
// 时间复杂度: O(n)
// 空间复杂度: O(1)
int maxSubArray_v2(vector<int> &nums)
{
    int n = nums.size();
    int dp = nums[0], result = dp;

    for (int i = 1; i < n; ++i)
    {
        dp = max(dp + nums[i], nums[i]);
        result = max(result, dp);
    }

    return result;
}

// 解法三：分治法
// 时间复杂度：O(n)
// 空间复杂度：O(logn)

// 对于任意区间，维护四个量：
// iSum: 区间和
// lSum: 从区间左端点出发的连续子数组最大和
// rSum: 以区间右端点出发的连续子数组最大和
// mSum：区间内的连续子数组最大和

// 当合并相连的左右两个区间 [l, m] 和 [m+1, r] 时：
// iSum = iSum1 + iSum2
// lSum = max(lSum1, iSum1 + lSum2)
// rSum = max(rSum2, rSum1 + iSum2)
// mSum = max(mSum1, mSum2, rSum1 + lSum2)

struct Status
{
    int iSum, lSum, rSum, mSum;
};

Status merge(Status left, Status right)
{
    int iSum = left.iSum + right.iSum;
    int lSum = max(left.lSum, left.iSum + right.lSum);
    int rSum = max(right.rSum, left.rSum + right.iSum);
    int mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum);
    return Status{iSum, lSum, rSum, mSum};
}

Status find(vector<int> &nums, int l, int r)
{
    if (l == r)
    {
        return Status{nums[l], nums[l], nums[l], nums[l]};
    }

    int mid = (l + r) / 2;
    return merge(find(nums, l, mid), find(nums, mid + 1, r));
}

int maxSubArray_v3(vector<int> &nums)
{
    return find(nums, 0, nums.size() - 1).mSum;
}