/*
 * 题目：21. 合并两个有序链表
 * 链接：https://leetcode.cn/problems/merge-two-sorted-lists/description/
 */

#include <iostream>
#include "mergeTwoLists.h"

void Test(ListNode *func(ListNode *, ListNode *), LinkList list1, LinkList list2, LinkList result)
{
    ListNode *head = func(list1.head, list2.head);

    LinkList res(head);
    if (res != result)
    {
        cerr << "result error: " << res << " != " << result << endl;
        return;
    }

    cout << "success" << endl;
}

int main()
{
    ListNode *(*func)(ListNode *, ListNode *) = mergeTwoLists_v2;

    Test(func, {1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});
    Test(func, {}, {}, {});
    Test(func, {}, {0}, {0});

    return 0;
}
