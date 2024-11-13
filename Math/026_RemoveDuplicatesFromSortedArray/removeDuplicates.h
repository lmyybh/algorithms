/*
 * 26. 删除有序数组中的重复项
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
 */

#include <vector>

using namespace std;

// 解法：快慢指针，快指针找到不重复的数，赋值给慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size();

    auto slow = nums.begin() + 1;
    for (auto fast = nums.begin() + 1; fast != nums.end(); ++fast)
    {
        if (*fast != *(fast - 1))
        {
            *slow = *fast;
            ++slow;
        }
    }
    return slow - nums.begin();
}