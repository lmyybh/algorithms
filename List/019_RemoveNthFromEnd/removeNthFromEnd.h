/*
 * 题目：19. 删除链表的倒数第 N 个结点
 * 链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 */
#include <vector>
#include "linkList.h"

// 解法：快慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0, head);

    ListNode *fast = dummy;
    ListNode *slow = dummy;

    while (n--)
        fast = fast->next;

    // fast 到达尾节点时，slow 位于倒数第 n+1 个节点
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // 删除节点
    ListNode *nthNode = slow->next;
    slow->next = nthNode->next;
    delete nthNode;
    nthNode = nullptr;

    head = dummy->next;
    delete dummy;

    return head;
}