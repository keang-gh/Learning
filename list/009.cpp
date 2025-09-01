/*******************************************************
 描述：单项循环链表的实现
 作者：周康
 注意：头节点中数据域不存数据，相当于dummy_head,一开始头尾共用
 时间：2023.6.19
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class CircleLink
{
public:
    CircleLink()
    {
        head_ = new Node;
        tail_ = head_;
        tail_->next_ = head_;
    }

    ~CircleLink()
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
    }

public:
    // 尾插法  O(1)
    void insertTail(int val)
    {
        Node *node = new Node(val);
        tail_->next_ = node;
        node->next_ = head_;
        tail_ = node;
    }

    // 头插法
    void insertHead(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        if (node->next_ == head_)
            tail_ = node;
    }

    // 删除节点  ---删1个
    void remove(int val)
    {
        Node *q = head_;
        Node *p = head_->next_;

        while (p != head_)
        {
            if (p->data_ == val) // 找到节点
            {
                q->next_ = p->next_;
                delete p;
                if (q->next_ == head_)
                    tail_ = q;
                return;
            }
            else
            {
                p = p->next_;
                q = q->next_;
            }
        }
    }

    // 查询
    bool find(int val) const
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
                return true;
            p = p->next_;
        }
        return false;
    }

    // 打印链表
    void show() const
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    struct Node
    {
        Node(int data = 0) : data_(data), next_(nullptr) {}
        int data_;
        Node *next_;
    };

    Node *head_; // 指向头节点
    Node *tail_; // 指向尾节点
};

int main()
{
    CircleLink clink;
    srand(time(nullptr));

    for (int i = 0; i < 10;i++)
    {
        clink.insertTail(rand() % 100);
    }
    clink.show();

    clink.insertHead(100);
    clink.insertHead(104);
    clink.show();

    cout << clink.find(100000) << endl;
    cout << clink.find(100) << endl;
    cout << clink.find(104) << endl;

    clink.insertTail(1999);
    clink.show();

    clink.remove(100);
    clink.show();
}