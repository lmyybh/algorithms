/*
 * 题目：19. 删除链表的倒数第 N 个结点
 * 链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 */

#include <iostream>
#include "removeNthFromEnd.h"

void Test(ListNode *(*func)(ListNode *, int), LinkList list, int n, LinkList result)
{
    list.changeFirstNode(func(list.firstNode(), n));

    if (list != result)
    {
        cerr << "result error: " << list << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    ListNode *(*func)(ListNode *, int) = removeNthFromEnd;

    Test(func, {1, 2, 3, 4, 5}, 2, {1, 2, 3, 5});
    Test(func, {1, 2}, 1, {1});
    Test(func, {1}, 1, {});

    return 0;
}
