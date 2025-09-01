/*******************************************************
 描述：约瑟夫环问题
 作者：周康
 案例：1，2，3，4，5，6，7，8  k---第几个人开始   m---报这个数的人撤
        1.k=1,m=3    result：3，6，1，5，2，8，4，7
        2.k=1,m=5    result: 5，2，8，7，1，4，6，3
        3.k=1,m=1    result: 1，2，3，4，5，6，7，8
 注意：引入dummy_head
 时间：2023.8.19
*******************************************************/
#include<iostream>
using namespace std;

struct Node
{
    Node(int data=0):data_(data),next_(nullptr){}
    int data_;
    Node *next_;
};

void josephus(Node *head, int k, int m)
{
    Node *s = head;
    while(s->next_!=nullptr)
        s = s->next_;
    s->next_ = head;

    Node *p = head;
    Node *q = head;

    //q指向最后一个
    while(q->next_!=head)
        q = q->next_;

    //从第k个开始报，p先走到第k个
    for (int i = 1; i < k;i++)
    {
        q = p;
        p = p->next_;
    }

    //开始报数
    for (;;)
    {
        for (int i = 1; i < m;i++)
        {
            q = p;
            p = p->next_;
        }

        cout << p->data_ << " ";

        if(p==q)
        {
            delete p;
            cout << endl;
            break;
        }

        // 删除p指向的节点
        q->next_ = p->next_;
        delete p;
        p = q->next_;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);

    head->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;
    n5->next_ = n6;
    n6->next_ = n7;
    n7->next_ = n8;

    josephus(head, 1, 1);

    return 0;
}