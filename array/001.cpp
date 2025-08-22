/*******************************************************
 描述：可扩容数组的类及类的常见接口功能测试代码
 作者：周康
 时间：2023.7
*******************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 数组实现
class MyArray
{
public:
    MyArray(int size = 10) : curcap_(0), cap_(size)
    {
        arr_ = new int[cap_]{};
    }

    ~MyArray()
    {
        delete[] arr_;
        arr_ = nullptr;
    }
//------------------------------------------------------------------------
public:
    // 末尾增加元素
    void push_back(int val)
    {
        if (curcap_ == cap_)     // O(n)
        {
            expand(2 * cap_);
        }
        arr_[curcap_++] = val;   // O(1)
    }

    // 末尾删除元素    O(1)
    void pop_back()
    {
        if(curcap_==0)
            return;
        
        curcap_--;
    }

    // 按位置增加元素
    void insert(int pos, int val)
    {
        if(pos<0 || pos>curcap_)
            return;
        
        if(curcap_==cap_)
            expand(2 * cap_);
        
        // 移动元素    O(n)
        for (int i = curcap_ - 1; i >= pos;i--)
        {
            arr_[i + 1] = arr_[i];
        }
        arr_[pos] = val;
        curcap_++;
    }

    // 元素查询返回pos
    int find(int val)
    {
        for (int i = 0; i < curcap_; i++)
        {
            if (arr_[i] == val)
                return i;
        }
        return -1;
    }

    // 按元素的位置删除元素
    void erase(int pos)
    {
        if(pos < 0 || pos >= curcap_)
            return;

        for (int i = pos + 1; i < curcap_;i++)
        {
            arr_[i - 1] = arr_[i];
        }
        
        curcap_--;
    }
    
    // 打印数据
    void show() const
    {
        for (int i = 0; i < curcap_; i++)
        {
            cout << arr_[i] << " ";
        }
        cout << endl;
    }

//--------------------------------------------------------------------------
private:
    int *arr_;    // 指向可扩容数组的内存
    int cap_;     // 数组的容量
    int curcap_;  // 数组有效元素个数,数组从0始 -> 尾元素的后继位置
//--------------------------------------------------------------------------
private:
    // 扩容接口
    void expand(int size)
    {
        int *p2 = new int[size];
        memcpy(p2, arr_, sizeof(int) * cap_);
        delete[] arr_;

        arr_ = p2;
        cap_ = size;
    }
};

int main()
{
    MyArray arr;
    srand(time(0));

    for (int i = 0; i < 10;i++)
    {
        arr.push_back(rand() % 100);
    }

    arr.show();
    cout << "*************删除末尾元素后************\n";
    arr.pop_back();
    arr.show();
    cout << "*************0号位置插入100后**********\n";
    arr.insert(0, 100);
    arr.show();
    cout << "*************10号位置插入200后*********\n";
    arr.insert(10, 200);
    arr.show();
    cout << "**************删除100后****************\n";
    int pos = arr.find(100);
    if(pos!=-1)
        arr.erase(pos);
    arr.show();

    return 0;
}