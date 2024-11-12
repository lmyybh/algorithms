/*
 * 题目：21. 合并两个有序链表
 * 链接：https://leetcode.cn/problems/merge-two-sorted-lists/description/
 */

#include <iostream>
#include "mergeTwoLists.h"

void Test(ListNode *func(ListNode *, ListNode *), LinkList list1, LinkList list2, LinkList result)
{
    list1.changeFirstNode(func(list1.firstNode(), list2.firstNode())); // 此时 list1 和 list2 存在共同节点
    list2.changeFirstNode(nullptr);                                    // list2 头节点指向 nullptr，避免析构时二次释放内存

    if (list1 != result)
    {
        cerr << "result error: " << list1 << " != " << result << endl;
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
