/*
 * 题目：24. 两两交换链表中的节点
 * 链接：https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 */

#include <iostream>
#include "swapPairs.h"

void Test(ListNode *func(ListNode *), LinkList list, LinkList result)
{
    ListNode *head = func(list.firstNode());
    list.changeFirstNode(head);

    LinkList res(head); // 复制链表内容，用于比较结果
    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    ListNode *(*func)(ListNode *) = swapPairs_v3;

    Test(func, {1, 2, 3, 4}, {2, 1, 4, 3});
    Test(func, {1}, {1});
    Test(func, {}, {});
    Test(func, {1, 2, 3}, {2, 1, 3});

    return 0;
}
