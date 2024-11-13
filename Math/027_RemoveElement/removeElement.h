/*
 * 27. 移除元素
 * https://leetcode.cn/problems/remove-element/
 */

#include <vector>

using namespace std;

// 解法一：快慢指针，快指针找到不为val 的数，赋值给慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int removeElement_v1(vector<int> &nums, int val)
{
    auto slow = nums.begin();
    for (auto fast = nums.begin(); fast != nums.end(); ++fast)
    {
        if (*fast != val)
        {
            *slow = *fast;
            ++slow;
        }
    }

    return slow - nums.begin();
}

// 解法一：快慢指针优化，快指针从右向左，赋值给慢指针为 val 的位置
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int removeElement_v2(vector<int> &nums, int val)
{
    if (nums.size() == 0)
        return 0;

    auto slow = nums.begin();
    auto fast = nums.end() - 1;

    while (slow <= fast)
    {
        if (*slow == val)
        {
            *slow = *fast;
            --fast;
        }
        else
        {
            ++slow;
        }
    }

    return slow - nums.begin();
}