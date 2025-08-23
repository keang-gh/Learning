/*******************************************************
 描述：单链表逆序
 思路：p指第一个有效节点，头节点看作一个空表，p遍历依次头插
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

Node* reverseLink(Node *head)
{
    Node *dummy_head=new Node;

    while(head!=nullptr)
    {
        Node *p = head->next_;
        head->next_ = dummy_head->next_;
        dummy_head->next_ = head;
        head = p;
    }

    Node *res_head = dummy_head->next_;
    delete dummy_head;
    return res_head;
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

    cout << "\n********反转后打印如下********\n";
    Node* res_head=reverseLink(head);
    show(res_head);
}