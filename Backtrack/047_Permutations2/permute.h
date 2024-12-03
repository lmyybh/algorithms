/*
 * 题目：47. 全排列 II
 * 链接：https://leetcode.cn/problems/permutations-ii/
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;

// 解法：回溯，借助交换位置生成全排列，需要剪枝避免重复
// 时间复杂度：O(n*n!)
// 空间复杂度：O(n^2)
void backtrack(vector<vector<int>> &res, vector<int> &nums, int index)
{
    if (index == nums.size() - 1)
    {
        res.push_back(nums);
        return;
    }

    set<int> used;
    for (int i = index; i < nums.size(); ++i)
    {
        // 剪枝，避免选择重复的数字
        if (used.find(nums[i]) != used.end())
            continue;

        used.insert(nums[i]);
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