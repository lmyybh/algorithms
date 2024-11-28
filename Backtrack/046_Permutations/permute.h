/*
 * 题目：46. 全排列
 * 链接：https://leetcode.cn/problems/permutations/description/
 */

#include <vector>
#include <iostream>

using namespace std;

// 解法：回溯，借助交换位置生成全排列
// 时间复杂度：O(n*n!)
// 空间复杂度：O(n)
void backtrack(vector<vector<int>> &res, vector<int> &nums, int index)
{
    if (index == nums.size() - 1)
    {
        res.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i)
    {
        swap(nums[i], nums[index]);
        backtrack(res, nums, index + 1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    backtrack(res, nums, 0);

    return res;
}