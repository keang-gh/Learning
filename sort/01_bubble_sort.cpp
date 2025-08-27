/*******************************************************
 描述：冒泡排序
 时间复杂度：最坏：O(n^2)    最好：O(n)
 空间复杂度：O(1)
 排序稳定性：稳定
 思路：1.两两比较，大的下沉（升序）；
       2.一趟下来，安排好尾数，后续处理除尾数的其余数
       3.如果一趟下来没有交换，就已经好了，据此优化
 作者：周康
 时间：2023.5.10
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bubbleSort(int arr[], int size) // 数组作为函数参数就退化成指针了，所以补充数组大小
{
    for (int i = 0; i < size - 1; i++) // 最后未排只有1元素
    {
        bool flag = false;
        // 趟数
        for (int j = 0; j < size - 1 - i; j++) // why:i-1   每次比较的是i与i+1
        {
            // 一趟的处理（优化：如果没有数据交换，说明好了）
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = true;
            }
        }
        if(!flag)
            return;
    }
}

int main()
{
    srand(time(nullptr));
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1; // rand
    }

    for (auto ele : arr)
    {
        cout << ele << " ";
    }

    cout << "\n***********冒泡排序后*********\n";
    bubbleSort(arr, 10);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
