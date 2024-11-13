/*
 * 题目：25. K 个一组翻转链表
 * 链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 */

#include <iostream>
#include "reverseKGroup.h"

void Test(ListNode *func(ListNode *, int), LinkList list, int k, LinkList result)
{
    ListNode *head = func(list.firstNode(), k);
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
    ListNode *(*func)(ListNode *, int) = reverseKGroup_v2;

    Test(func, {1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5});
    Test(func, {1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5});
    Test(func, {1, 2}, 2, {2, 1});

    return 0;
}
