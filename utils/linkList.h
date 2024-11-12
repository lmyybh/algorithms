#include <initializer_list>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkList
{
private:
    ListNode *dummy = new ListNode(-1);
    unsigned int size = 0;

public:
    LinkList() : dummy(new ListNode(-1)), size(0) {}
    LinkList(ListNode *node)
    {
        while (node)
        {
            push_back(node->val);
            node = node->next;
        }
    }
    LinkList(initializer_list<int> nums)
    {
        for (auto it = nums.begin(); it != nums.end(); ++it)
            push_back(*it);
    }

    ~LinkList()
    {
        clearNodes();
        delete dummy;
    }

    // 拷贝构造函数
    LinkList(const LinkList &list)
    {
        if (list.empty())
            return;

        ListNode *node = list.firstNode();
        while (node)
        {
            push_back(node->val);
            node = node->next;
        }
    }

    // 拷贝赋值运算符
    LinkList &operator=(const LinkList &list)
    {
        LinkList temp(list);
        clearNodes();

        ListNode *node = list.firstNode();
        while (node)
        {
            push_back(node->val);
            node = node->next;
        }

        return *this;
    }

    ListNode *firstNode() const
    {
        return dummy->next;
    }

    ListNode *lastNode() const
    {
        ListNode *cur = dummy;
        while (cur->next)
            cur = cur->next;

        return cur;
    }

    void push_back(int x)
    {
        lastNode()->next = new ListNode(x);
        ++size;
    }

    void clearNodes()
    {
        ListNode *cur = dummy->next;
        while (cur)
        {
            ListNode *next = cur->next;
            delete cur;
            cur = next;
        }
        dummy->next = nullptr;
        size = 0;
    }

    unsigned int length() const
    {
        return size;
    }

    bool empty() const
    {
        return length() == 0;
    }

    void changeFirstNode(ListNode *head)
    {
        dummy->next = head;
        size = 0;
        while (head)
        {
            ++size;
            head = head->next;
        }
    }
};

bool operator==(const LinkList &lhs, const LinkList &rhs)
{
    ListNode *l = lhs.firstNode();
    ListNode *r = rhs.firstNode();

    while (l && r)
    {
        if (l->val != r->val)
            return false;
        l = l->next;
        r = r->next;
    }

    return (!l) && (!r);
}

bool operator!=(const LinkList &lhs, const LinkList &rhs)
{
    return !(lhs == rhs);
}

ostream &operator<<(ostream &os, const LinkList &list)
{
    ListNode *cur = list.firstNode();
    while (cur != nullptr)
    {
        os << cur->val;
        cur = cur->next;
        if (cur != nullptr)
            os << ", ";
    }

    return os;
}