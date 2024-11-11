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
public:
    LinkList() : head(nullptr) {}
    LinkList(ListNode *_head)
    {
        copy_from_head(_head);
    }
    LinkList(initializer_list<int> nums)
    {
        if (nums.size() == 0)
        {
            head = nullptr;
            return;
        }

        for (auto it = nums.begin(); it != nums.end(); ++it)
            insert(*it);
    }

    ~LinkList()
    {
        clear();
    }

    // 拷贝构造函数
    LinkList(const LinkList &list)
    {
        copy_from_head(list.head);
    }

    // 拷贝赋值运算符
    LinkList &operator=(const LinkList &list)
    {
        // LinkList temp(list); // 复制，防止自我赋值时释放两次
        copy_from_head(list.head);

        return *this;
    }

    void insert(int x)
    {
        if (!head)
        {
            head = new ListNode(x);
            return;
        }

        ListNode *cur = head;
        while (cur->next)
            cur = cur->next;

        cur->next = new ListNode(x);
    }

    void clear()
    {
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            delete cur;
            cur = next;
        }
        head = nullptr;
    }

    void copy_from_head(ListNode *_head)
    {
        if (!_head)
            return;

        ListNode *cur = _head;
        while (cur)
        {
            insert(cur->val);
            cur = cur->next;
        }
    }

public:
    ListNode *head = nullptr;
};

bool operator==(const LinkList &lhs, const LinkList &rhs)
{
    ListNode *l = lhs.head;
    ListNode *r = rhs.head;

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
    ListNode *cur = list.head;
    while (cur != nullptr)
    {
        os << cur->val;
        cur = cur->next;
        if (cur != nullptr)
            os << ", ";
    }

    return os;
}