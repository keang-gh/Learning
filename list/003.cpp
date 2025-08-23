/*******************************************************
 描述：求单链表倒数第k个节点
 思路：双指针法，p先指向正向第k个（先走），后面一起走，最后p指空，q就是
 作者：周康
 时间：2023.7.15
*******************************************************/
#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : val_(data), next_(nullptr) {}

    int val_;
    Node *next_;
};

bool getLastKNode(Node *head, int k)
{
    Node *dummy_head = new Node;
    dummy_head->next_ = head;
    Node *p = dummy_head;
    Node *q = dummy_head;

    for (int i = 0; i < k; i++)
    {
        p = p->next_;
        if (p == nullptr)
            return false;
    }

    while (p != nullptr)
    {
        p = p->next_;
        q = q->next_;
    }
    cout << "这个值存在，值为：" << q->val_ << endl;
    return true;
}

void show(Node *head)
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->val_ << " ";
        p = p->next_;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next_ = new Node(3);
    head->next_->next_ = new Node(5);
    head->next_->next_->next_ = new Node(7);
    head->next_->next_->next_->next_ = new Node(9);
    show(head);

    cout << "\n******************************\n";
    bool b = getLastKNode(head, 49);

    if (b == false)
        cout << "这个值不存在!\n";

    return 0;
}
