/*
 * 31. 下一个排列
 * https://leetcode.cn/problems/next-permutation/
 */

#include <vector>
#include <algorithm>

using namespace std;

// 解法：等价于找到下一比当前数字大的数，即把后面的大数与前面的小数交换，且保证交换后的结果最小
// 时间复杂度：O(N)
// 空间复杂度：O(1)
void nextPermutation(vector<int> &nums)
{
    // 倒序遍历
    auto it = nums.end() - 2;
    for (; it >= nums.begin(); --it)
    {
        // 找到第一个比后面数字小的数
        if (*it < *(it + 1))
        {
            // 找到该数字后面，比该数字大的最小的数，并交换
            auto swapIter = it + 1;
            for (auto it2 = swapIter + 1; it2 != nums.end(); ++it2)
            {
                if (*it2 > *it && *it2 <= *swapIter) // 需要用 <=，保证交换后，后续数字按降序排列
                {
                    swapIter = it2;
                }
            }
            swap(*it, *swapIter);

            break;
        }
    }

    // 交换后，后续序列一定是降序排列，改为升序即可得到结果
    reverse(it + 1, nums.end());
}