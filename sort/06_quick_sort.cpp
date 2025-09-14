/*******************************************************
 描述：快速排序
 时间复杂度：平均 O(nlogn)  最好：O(nlogn)  最坏：O(n^2)
 空间复杂度：O(logn)-O(n)
 排序稳定性：不稳定
 思路：递归
 作者：周康
 时间：2024.5.17
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 快排分割处理函数
int partition(int arr[], int l, int r)
{
    int val = arr[l];
    while (l < r)
    {
        while (l < r && arr[r] > val)
            r--;

        if (l < r)
        {
            arr[l] = arr[r];
            l++;
        }

        while (l < r && arr[l] < val)
            l++;

        if (l < r)
        {
            arr[r] = arr[l];
            r--;
        }
    }

    // l==r的位置，就是放基准数的位置
    arr[l] = val;
    return l;
}

void quickSort(int arr[], int begin, int end) // 对数组递归，应是范围
{
    // 递归终止条件
    if (begin >= end)
        return;

    // 在[begin,end]做一次快排分割处理，做完基准数放在pos处，pos左都小，右都大
    int pos = partition(arr, begin, end);

    // 对左右继续做快排
    quickSort(arr, begin, pos - 1);
    quickSort(arr, pos + 1, end);
}

void quickSort(int arr[], int size)
{
    return quickSort(arr, 0, size - 1);
}

int main()
{
    srand(time(nullptr));
    int arr[10];

    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 100 + 1;

    for (int ele : arr)
        cout << ele << " ";
    cout << endl;

    // 快速排序
    int size1 = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, size1);
    cout << "快速排序后：\n";
    
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;

    return 0;
}