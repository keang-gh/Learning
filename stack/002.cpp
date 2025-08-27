/*******************************************************
 描述：实现链式栈（使用的时候直接使用C++容器适配器stack）
 思路：链表的头插(入栈)与头删（出栈）  引入虚拟头节点方便处理
 作者：周康
 时间：2023.6.10
*******************************************************/
#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

class LinkStack
{
public:
    LinkStack():size_(0)
    {
        head_ = new Node;
    }

    ~LinkStack()
    {
        Node *p = head_;
        while(p!=nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

public:
    // 入栈    O(1)
    void push(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        size_++;
    }

    // 出栈    O(1)
    void pop()
    {
        if (head_->next_ == nullptr)
            throw "stack is empty!";

        Node *p = head_->next_;
        head_->next_ = p->next_;
        delete p;
        size_--;
    }

    // 获取栈顶元素
    int top() const
    {
        if(head_->next_==nullptr)
            throw "stack is empty!";
        return head_->next_->data_;
    }

    // 判空
    bool empty() const
    {
        return head_->next_ == nullptr;
    }

    // 返回栈元素个数
    int size() const
    {
        return size_;
    }

private:
    Node *head_;
    int size_;
};

int main()
{
    int arr[]{1, 3, 5, 7, 9};
    LinkStack s;

    for(int ele:arr)
    {
        s.push(ele);
    }

    cout << s.size() << endl;
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << s.size() << endl;
    // s.top();

    cout << endl;
}
