/*
 * 题目：23. 合并 K 个升序链表
 * 链接：https://leetcode.cn/problems/merge-k-sorted-lists/description/
 */

#include <iostream>
#include <initializer_list>
#include "mergeKLists.h"

void Test(ListNode *func(vector<ListNode *> &), initializer_list<initializer_list<int>> lists, LinkList result)
{
    vector<LinkList> linkLists;
    for (auto l : lists)
    {
        linkLists.push_back(LinkList(l));
    }

    vector<ListNode *> nodes;
    for (auto &l : linkLists)
    {
        nodes.push_back(l.firstNode());
    }

    ListNode *head = func(nodes);
    if (head) // head 不为空指针时，linkLists 长度一定大于 0
    {
        linkLists[0].changeFirstNode(head); // 第一个链表改变头节点
        for (int i = 1; i < linkLists.size(); ++i)
            linkLists[i].changeFirstNode(nullptr); // 其他链表头节点置空，避免重复释放内存
    }

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
    ListNode *(*func)(vector<ListNode *> &) = mergeKLists_v3;

    Test(func, {{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
    Test(func, {{1, 2, 4}, {1, 3, 4}}, {1, 1, 2, 3, 4, 4});
    Test(func, {}, {});
    Test(func, {{}, {0}}, {0});

    return 0;
}
