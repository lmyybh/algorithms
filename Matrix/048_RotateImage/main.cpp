/*
 * 题目：48. 旋转图像
 * 链接：https://leetcode.cn/problems/rotate-image/description/
 */

#include <iostream>
#include "rotate.h"
#include "../../utils/str.h"

void Test(void func(vector<vector<int>> &), vector<vector<int>> matrix, vector<vector<int>> result)
{
    func(matrix);

    if (matrix != result)
    {
        cerr << "result error: " << Vector2dToString(matrix) << " != " << Vector2dToString(result) << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    void (*func)(vector<vector<int>> &) = rotate;

    Test(func, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});
    Test(func, {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}, {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}});

    return 0;
}
