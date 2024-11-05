/*
 * 题目：4. 寻找两个正序数组的中位数
 * 链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 */

#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// 解法一：双指针，从小到大递增，直到达到中位数位置
// 时间复杂度：O(m+n)
// 空间复杂度：O(1)
double findMedianSortedArrays_v1(vector<int> &nums1, vector<int> &nums2)
{
    auto it1 = nums1.cbegin();
    auto it2 = nums2.cbegin();
    int target = (nums1.size() + nums2.size()) / 2;
    int pre = 0, cur = 0;

    for (int i = 0; i <= target; ++i)
    {
        pre = cur;

        if (it1 != nums1.cend() && (it2 == nums2.cend() || *it1 <= *it2))
        {
            cur = *(it1++);
        }
        else
        {
            cur = *(it2++);
        }
    }

    double res = cur;
    if ((nums1.size() + nums2.size()) % 2 == 0)
    {
        res = (pre + cur) / 2.0;
    }

    return res;
}

// 解法二：二分法，问题转化为给定两个有序数组，求第 k 小的数
// 时间复杂度：O(log(m+n))
// 空间复杂度：O(1)
double findK(vector<int> &nums1, vector<int>::const_iterator cb1,
             vector<int> &nums2, vector<int>::const_iterator cb2, int k)
{
    int len1 = nums1.cend() - cb1;
    int len2 = nums2.cend() - cb2;

    if (len1 == 0)
    {
        return *(cb2 + k - 1);
    }

    if (len2 == 0)
    {
        return *(cb1 + k - 1);
    }

    if (k == 1)
    {
        return min({*cb1, *cb2});
    }

    // 二分，比较第 k / 2 个数，跳过较小的部分
    int t = min({k / 2, len1, len2});

    if (*(cb1 + t - 1) <= *(cb2 + t - 1))
    {
        return findK(nums1, cb1 + t, nums2, cb2, k - t);
    }
    else
    {
        return findK(nums1, cb1, nums2, cb2 + t, k - t);
    }
}

double findMedianSortedArrays_v2(vector<int> &nums1, vector<int> &nums2)
{
    int length = nums1.size() + nums2.size();
    int k = length / 2 + 1;

    double res = findK(nums1, nums1.cbegin(), nums2, nums2.cbegin(), k);
    if (length % 2 == 0)
    {
        res += findK(nums1, nums1.cbegin(), nums2, nums2.cbegin(), k - 1);
        res /= 2.0;
    }

    return res;
}

// 解法三：二分遍历较小数组的分割线位置
// 时间复杂度：O(log(min(m, n)))
// 空间复杂度：O(1)
double findMedianSortedArrays_v3(vector<int> &nums1, vector<int> &nums2)
{
    vector<int>::size_type m = nums1.size();
    vector<int>::size_type n = nums2.size();

    if (m > n)
    {
        return findMedianSortedArrays_v3(nums2, nums1);
    }

    vector<int>::size_type t = (m + n) / 2;
    vector<int>::size_type i, j;

    vector<int>::size_type left = 0, right = m;

    while (left <= right)
    {
        i = (left + right) / 2;
        j = t - i;

        if ((i < 1 || nums1[i - 1] <= nums2[j]) && (i >= m || nums2[j - 1] <= nums1[i]))
        {
            break;
        }

        if (i >= 1 && nums1[i - 1] > nums2[j])
        {
            right = i - 1;
        }
        else if (i < m && nums2[j - 1] > nums1[i])
        {
            left = i + 1;
        }
    }

    double res = min({i < m ? nums1[i] : INT_MAX, j < n ? nums2[j] : INT_MAX});
    if ((m + n) % 2 == 0)
    {
        res += max({i >= 1 ? nums1[i - 1] : INT_MIN, j >= 1 ? nums2[j - 1] : INT_MIN});
        res /= 2.0;
    }

    return res;
}