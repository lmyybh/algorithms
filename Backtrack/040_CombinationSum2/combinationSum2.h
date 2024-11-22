/*
 * 题目：40. 组合总和 II
 * 链接：https://leetcode.cn/problems/combination-sum-ii/description/
 */

#include <vector>
#include <algorithm>

using namespace std;

// 解法：回溯
// 时间复杂度：O((e^pi * sqrt((2/3)*target)) / target)
// 空间复杂度：O(target) combination 长度和递归深度最多到 target

void backtrack(const vector<int> &candidates, vector<vector<int>> &result, int target, vector<int> combination, int index)
{
    // target 记录减去已有 combination 外的目标值
    if (target == 0)
    {
        result.push_back(combination);
        return;
    }

    if (target < 0)
        return;

    // index 表示当前可以选择的数字的 index
    for (int i = index; i < candidates.size(); ++i)
    {
        // 因为排序的原因，循环的数大于 target时，可以提前跳出
        if (candidates[i] > target)
            break;

        // 剪枝，跳过相同元素
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        combination.push_back(candidates[i]);
        backtrack(candidates, result, target - candidates[i], combination, i + 1);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    // 排序，用于后续提前跳出回溯
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> combination;

    backtrack(candidates, res, target, combination, 0);

    return res;
}