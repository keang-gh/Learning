/*******************************************************
 描述：判断单链表是否有环及环的入口节点(力扣142)
 思路：双指针（快慢指针）
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

Node *detectCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;

        if (fast == slow)
        {
            Node *index1 = fast;
            Node *index2 = head;

            while (index1 != index2)
            {
                index1 = index1->next_;
                index2 = index2->next_;
            }
            return index2;
        }
    }
    return nullptr;
}

int main()
{
    Node *head = new Node(1);
    head->next_ = new Node(3);
    head->next_->next_ = new Node(5);
    head->next_->next_->next_ = new Node(7);
    head->next_->next_->next_->next_ = new Node(9);
    //head->next_->next_->next_->next_->next_ = head->next_->next_;

    if (detectCycle(head))
    {
        cout << "有环，其节点值是：" << detectCycle(head)->data_ << endl;
    }
    else
        cout << "无环\n";
}