/*******************************************************
 描述：合并两个有序单链表
 思路：双指针思想
 作者：周康
 时间：2023.7.10
*******************************************************/
#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}

    int data_;
    Node *next_;
};

void show(Node *head)
{
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data_ << " ";
        cur = cur->next_;
    }
}

Node *mergeTwoLists(Node *head1, Node *head2)
{
    Node *dummy_head_1 = new Node;
    dummy_head_1->next_ = head1;
    Node *dummy_head_2 = new Node;
    dummy_head_2->next_ = head2;

    Node *p = dummy_head_1->next_;
    Node *q = dummy_head_2->next_;
    Node *last = dummy_head_1;

    while (p != nullptr && q != nullptr)
    {
        if (p->data_ < q->data_)
        {
            last->next_ = p;
            p = p->next_;
            last = last->next_;
        }
        else
        {
            last->next_ = q;
            q = q->next_;
            last = last->next_;
        }
    }

    if (p != nullptr)
        last->next_ = p;
    else
        last->next_ = q;

    Node *res_head = dummy_head_1->next_;
    delete dummy_head_1;
    dummy_head_1 = nullptr;
    return res_head;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next_ = new Node(3);
    head1->next_->next_ = new Node(5);
    head1->next_->next_->next_ = new Node(7);
    show(head1);
    cout << endl;

    Node *head2 = new Node(2);
    head2->next_ = new Node(4);
    head2->next_->next_ = new Node(6);
    head2->next_->next_->next_ = new Node(8);
    show(head2);
    cout << endl;

    show(mergeTwoLists(head1, head2));
}