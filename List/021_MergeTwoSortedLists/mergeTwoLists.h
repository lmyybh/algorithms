/*
 * 题目：21. 合并两个有序链表
 * 链接：https://leetcode.cn/problems/merge-two-sorted-lists/description/
 */

#include <vector>
#include "linkList.h"

// 解法一：递归
// 时间复杂度：O(m+n)
// 空间复杂度：O(m+n)
ListNode *mergeTwoLists_v1(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    else if (!list2)
        return list1;

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists_v1(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists_v1(list1, list2->next);
        return list2;
    }
}

// 解法二：迭代
// 时间复杂度：O(m+n)
// 空间复杂度：O(1)
ListNode *mergeTwoLists_v2(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    else if (!list2)
        return list1;

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    cur->next = !list1 ? list2 : list1;

    ListNode *head = dummy->next;
    delete dummy;

    return head;
}