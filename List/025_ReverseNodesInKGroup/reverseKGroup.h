/*
 * 题目：25. K 个一组翻转链表
 * 链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 */
#include <deque>
#include "../../utils/linkList.h"

// 解法一：借助双端队列，前面的每 k 个元素先入后出，反序节点，最后不足 k 个元素先入先出，保持顺序
// 时间复杂度：O(n)
// 空间复杂度：O(k)
ListNode *reverseKGroup_v1(ListNode *head, int k)
{
    deque<ListNode *> deque;

    ListNode dummy(-1);
    ListNode *lastNode = &dummy;

    ListNode *cur = head;
    while (cur || !deque.empty())
    {
        if (deque.size() < k && cur)
        {
            deque.push_back(cur);
            cur = cur->next;
        }
        else
        {
            // 最后不足 k 个元素时，先入先出
            bool popFront = !cur && deque.size() < k;

            ListNode *node;
            while (!deque.empty())
            {
                if (!popFront)
                {
                    node = deque.back();
                    deque.pop_back();
                }
                else
                {
                    node = deque.front();
                    deque.pop_front();
                }

                lastNode->next = node;
                lastNode = lastNode->next;
                lastNode->next = nullptr;
            }
        }
    }

    return dummy.next;
}

// 解法二：模拟，每 k 个节点，执行一次反转链表
// 时间复杂度：O(n)
// 空间复杂度：O(1)
void reverseList(ListNode *lastTail, ListNode *begin, ListNode *end)
{
    ListNode *one = begin;
    ListNode *two = one->next;

    while (one != end)
    {
        ListNode *temp = two->next;
        two->next = one;
        one = two;
        two = temp;
    }

    lastTail->next = end;
    begin->next = two;
}

ListNode *reverseKGroup_v2(ListNode *head, int k)
{
    // 小于或等于一个节点时，直接返回
    if (!head || !head->next || k == 1)
        return head;

    ListNode dummy(-1, head);
    ListNode *lastTail = &dummy; // lastTail 代表之前的尾节点
    ListNode *begin = head;

    while (begin)
    {
        // 前进 k 次，找到停止节点
        ListNode *end = lastTail;
        for (int i = 0; i < k; ++i)
        {
            end = end->next;
            if (!end)
                return dummy.next;
        }

        // 反序 begin 到 end
        reverseList(lastTail, begin, end);

        // 更新节点
        lastTail = begin;       // 反序后，begin 是尾节点
        begin = lastTail->next; // 开始节点是尾节点的下一个节点
    }

    return dummy.next;
}