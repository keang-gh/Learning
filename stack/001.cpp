/*******************************************************
 描述：实现顺序栈（使用的时候直接使用C++容器适配器stack）
 作者：周康
 时间：2023.6.10
*******************************************************/
#include <iostream>
#include <string.h>
using namespace std;

class SeqStack
{
public:
    SeqStack(int size = 10) : top_(0), cap_(size)
    {
        pstack_ = new int[cap_];
    }

    ~SeqStack()
    {
        delete[] pstack_;
        pstack_ = nullptr;
    }

public:
    // 入栈
    void push(int val)
    {
        if (top_ == cap_)
        {
            // 扩容
            expand(2 * cap_);
        }
        pstack_[top_++] = val;
    }

    // 出栈
    void pop()
    {
        if (top_ == 0)
            throw "stack is empty!";
        top_--;
    }

    // 获取栈顶元素
    int top() const
    {
        if (top_ == 0)
            throw "stack is empty!";
        return pstack_[top_ - 1];
    }

    // 判断栈空与否
    bool empty() const
    {
        return top_ == 0;
    }

    // 栈元素个数
    int size() const
    {
        return top_;
    }

private:
    int *pstack_;
    int top_;
    int cap_;

private:
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, pstack_, top_ * sizeof(int));
        delete[] pstack_;
        pstack_ = p;
        cap_ = size;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    SeqStack s;

    for (int ele : arr)
    {
        s.push(ele);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    s.top();
}