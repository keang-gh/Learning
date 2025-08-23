/*******************************************************
 描述：实现单链表
 作者：周康
 时间：2023.7.15
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 节点类型
struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}

    int data_;
    Node *next_;
};

// 单链表代码实现
class MyLink
{
public:
    MyLink()
    {
        // 给head_初始化指向头节点
        head_ = new Node();
    }

    ~MyLink()
    {
        // 节点的释放 尽量不引入变量 head也要释放，就作为移动指针，免得再定义指针
        Node *p = head_;
        while(p!=nullptr)
        {
            head_ = p->next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }
//----------------------
public:
    // 链表的尾插法   O(n)
    void insertTail(int val)
    {
        // 找到当前链表的尾节点
        Node *p = head_;
        while(p->next_!=nullptr)
        {
            p = p->next_;
        }

        // 生成新节点
        Node *node = new Node(val);
        p->next_ = node;
    }

    // 链表的头插法 （先后再前，不然找不到后）  O(1)
    void insertHead(int val)
    {
        Node *node = new Node(val);

        node->next_ = head_->next_;
        head_->next_ = node;
    }

    // 链表节点删除 （注:这里指第一次出现的节点）
    void remove(int val)
    {
        // p是当前，找到 -> 连接前后 -> delete p     
        // 用2个指针，前随后动，位差为1
        Node *q = head_;
        Node *p = head_->next_;

        while(p!=nullptr)
        {
            if(p->data_==val)
            {
                q->next_ = p->next_;
                delete p;
                return;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
        return;
    }

    // 删除全部值为val的节点
    void removeAll(int val)
    {
        // 需要继续删除，只需 p = q->next;
        Node *q = head_;
        Node *p = head_->next_;

        while(p!=nullptr)
        {
            if(p->data_==val)
            {
                q->next_ = p->next_;
                delete p;
                // 对指针p进行重置
                p = q->next_;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }

    // 搜索-元素有无判断    O(n)
    bool find(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
                return true;
            else
                p = p->next_;
        }
        return false;
    }

    // 链表打印
    void show()
    {
        Node *p = head_->next_;
        while (p!= nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }
//-----------------------
    Node *head_; // 指向链表的头节点
};



int main()
{
    MyLink link;
    srand(time(0));
    for (int i = 0; i < 10;i++)
    {
        int val=rand()%100;
        //link.insertTail(val);
        link.insertHead(val);
        //cout << val << " ";
    }

    //cout << "\n***********尾插打印*************\n";
    //cout << "\n***********头插打印*************\n";
    //link.show();

    link.insertHead(99);
    link.insertHead(24);
    link.insertHead(99);
    link.insertTail(99);
    cout << "***********删除前的数组*************\n";
    link.show();

    // link.remove(99);
    // cout << "***********删除第一个99后的数组*************\n";
    // link.show();

    link.removeAll(99);
    cout << "***********删除全部99后的数组*************\n";
    link.show();

    return 0;
}