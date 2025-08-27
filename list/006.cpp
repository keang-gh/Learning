/*******************************************************
 描述：判断两个链表是否相交（力扣160）
 思路：1.哈希表
      2.遍历长度求差，长的先走再一起走，遇见就相交（采用此思路）
 作者：周康
 时间：2023.7.11
*******************************************************/
#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

bool getIntersectionNode(Node *head1, Node *head2)
{
    int lk_num1 = 0, lk_num2 = 0;
    Node *p = head1;
    Node *q = head2;

    while (p != nullptr)
    {
        lk_num1++;
        p = p->next_;
    }

    while (q != nullptr)
    {
        lk_num2++;
        q = q->next_;
    }

    // 重置一下
    p = head1;
    q = head2;

    if (lk_num1 > lk_num2)
    {
        // 第一个链表长
        int diff = lk_num1 - lk_num2;
        for (int i = 0; i < diff; i++)
        {
            p = p->next_;
        }
    }
    else
    {
        int diff = lk_num2 - lk_num1;
        for (int i = 0; i < diff; i++)
        {
            q = q->next_;
        }
    }

    while (p != nullptr && q != nullptr)
    {
        if (p == q)
        {
            cout << "相交且相交点的值为：" << q->data_ << endl;
            return true;
        }

        p = p->next_;
        q = q->next_;
    }
    return false;
}

int main()
{

    Node *head1 = new Node(1);
    head1->next_ = new Node(3);
    head1->next_->next_ = new Node(5);

    Node *head2 = new Node(2);
    head2->next_ = new Node(4);
    head2->next_->next_ = new Node(6);
    head2->next_->next_ = head1->next_;

    bool b = getIntersectionNode(head1, head2);
    if (b == false)
        cout << "不相交!\n";

    return 0;
}