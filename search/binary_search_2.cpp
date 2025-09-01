/*******************************************************
 描述：二分搜索（递归）
 时间复杂度：O(logn)，why：相当于BST搜索，层数k就是最多次，节点数之和就是n，由k与n关系求
 思路：
     1.递归的特点之一是数据规模的减少，以此感性定位形参，后理性论证(这里就是p & q)；
     2.确定"递"终止的条件；
     3.找到实现功能且是调用自己的逻辑写法。
 作者：周康
 时间：2023.6.11
*******************************************************/
#include <iostream>
using namespace std;

int binarySearch(int arr[],int p,int q,int tgt)
{
    if(p>q)
        return -1;

    int mid = p + ((q - p) / 2);
    if(arr[mid]==tgt)
        return mid;
    else if(arr[mid]>tgt)
        return binarySearch(arr,p, mid - 1, tgt);
    else
        return binarySearch(arr, mid + 1, q, tgt);
}

int main()
{
    int setval = 0;
    cout << "请输入你要查找的值：";
    cin >> setval;
    int arr[7]{1, 3, 4, 5, 6, 7, 19};
    int res = binarySearch(arr, 0, 6,setval);
    if (res==-1)
        cout << "不存在！\n";
    else
        cout<<"要找的值所在的数组下标是："<<res<<endl;
}