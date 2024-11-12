/*
 * 题目：24. 两两交换链表中的节点
 * 链接：https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 */

#include <stack>
#include "../../utils/linkList.h"

// 解法一：借助栈，先入后出，反序相邻节点
// 时间复杂度：O(n)
// 空间复杂度：O(1)
ListNode *swapPairs_v1(ListNode *head)
{
    stack<ListNode *> stack;

    ListNode dummy(-1);
    ListNode *lastNode = &dummy;

    ListNode *cur = head;
    while (cur || !stack.empty())
    {
        if (stack.size() < 2 && cur)
        {
            stack.push(cur);
            cur = cur->next;
        }
        else
        {
            while (!stack.empty())
            {
                ListNode *node = stack.top();
                stack.pop();
                lastNode->next = node;
                lastNode = lastNode->next;
                lastNode->next = nullptr;
            }
        }
    }

    return dummy.next;
}

// 解法二：递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
ListNode *swapPairs_v2(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *one = head;
    ListNode *two = one->next;
    ListNode *three = two->next;

    two->next = one;
    one->next = swapPairs_v2(three);

    return two;
}

// 解法三：迭代
// 时间复杂度：O(n)
// 空间复杂度：O(1)
ListNode *swapPairs_v3(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode dummy = ListNode(-1, head);

    ListNode *pre = &dummy;
    ListNode *one = pre->next;
    ListNode *two = one->next;

    while (one && two)
    {
        // 交换 one 和 two
        one->next = two->next;
        two->next = one;
        pre->next = two;

        // 更新节点
        pre = one;
        one = pre->next;
        if (!one)
            break;

        two = one->next;
    }

    return dummy.next;
}