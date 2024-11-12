/*
 * 题目：21. 合并两个有序链表
 * 链接：https://leetcode.cn/problems/merge-two-sorted-lists/description/
 */

#include <vector>
#include <climits>
#include <queue>
#include "../../utils/linkList.h"

/* -------------------------------------------------------------------- */
// 解法一：递归：每次比较头节点，选出最小的
// 时间复杂度：O(k^2 * n) k为链表数量，n为每个链表最大元素个数
// 空间复杂度：O(kn)
ListNode *mergeKLists_v1(vector<ListNode *> &lists)
{
    int minVal = INT_MAX;
    int minIdx = -1;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (lists[i] && lists[i]->val < minVal)
        {
            minVal = lists[i]->val;
            minIdx = i;
        }
    }

    if (minIdx < 0)
        return nullptr;

    ListNode *node = lists[minIdx];
    lists[minIdx] = lists[minIdx]->next;
    node->next = mergeKLists_v1(lists);
    return node;
}

/* -------------------------------------------------------------------- */
// 解法二：分治，k个链表分为两份合并
// 时间复杂度：O(kn * logk)
// 空间复杂度：O(logk)

// 迭代法，实现两个链表合并
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
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

ListNode *merge(vector<ListNode *> &lists, int l, int r)
{
    if (l == r)
        return lists[l];

    int mid = (l + r) / 2;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

ListNode *mergeKLists_v2(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    return merge(lists, 0, lists.size() - 1);
}

/* -------------------------------------------------------------------- */
// 解法三：优先队列，插入全部头节点，每次取出最小节点，并插入其下一个节点
// 时间复杂度：O(kn * logk) 优先队列的插入和删除代价为 logk
// 空间复杂度：O(k) 优先队列最多有 k 个元素
ListNode *mergeKLists_v3(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

    for (auto node : lists)
    {
        if (node)
            pq.push(node);
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();
        cur->next = node;
        cur = cur->next;
        if (node->next)
        {
            pq.push(node->next);
        }
    }

    return dummy->next;
}