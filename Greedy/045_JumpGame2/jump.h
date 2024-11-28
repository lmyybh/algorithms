/*
 * 题目：45. 跳跃游戏 II
 * 链接：https://leetcode.cn/problems/jump-game-ii/description/
 */

#include <vector>
#include <iostream>

using namespace std;

// 解法：贪心，每次选择最远的位置
// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 题解：https://leetcode.cn/problems/jump-game-ii/solutions/2926993/tu-jie-yi-zhang-tu-miao-dong-tiao-yue-yo-h2d4/
int jump(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    int cur = 0;         // cur 表示当前的位置
    int maxPosition = 0; // maxPosition 表示遍历到的可以到达的最右侧位置
    for (int i = 0; i < n - 1; ++i)
    {
        maxPosition = max(maxPosition, i + nums[i]);

        if (i == cur)
        {
            cur = maxPosition;
            ++res;
        }
    }

    return res;
}