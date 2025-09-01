/*******************************************************
 描述：二分搜索（非递归）
 时间复杂度：O(logn)，why：相当于BST搜索，层数k就是最多次，节点数之和就是n，由k与n关系求
 思路：因为有序，类比猜数字。100W -> 最多20次，1000w -> 最多24次
 作者：周康
 时间：2023.6.11
*******************************************************/
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int tgt)
{
    int p = 0;
    int q = size - 1;
    while (p <= q)
    {
        int mid = p + ((q - p) / 2);
        if (arr[mid] == tgt)
            return mid;
        else if (tgt > arr[mid])
            p = mid + 1;
        else
            q = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[10]{1, 3, 5, 7, 9, 11, 13};
    int res = binarySearch(arr, 7, 13);
    if (res == -1)
        cout << "不存在\n";
    else
        cout << "这个数的下标是：" << res << endl;

    return 0;
}