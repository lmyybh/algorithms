/*
 * 题目：48. 旋转图像
 * 链接：https://leetcode.cn/problems/rotate-image/description/
 */

#include <vector>
#include <iostream>

using namespace std;

// 解法：先转置，后翻转每一行
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int temp; // 中间量，用于交换元素

    // 矩阵转置
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // 反转矩阵每一行
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}