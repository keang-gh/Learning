/*******************************************************
 描述：希尔排序
 时间复杂度：平均 <O(n^2)  最好：O(n)  最坏：O(n^2)
 空间复杂度：O(1)
 排序稳定性：不稳定
 思路：将序列尽量排为全局有序，主体按插入排序的思路
 作者：周康
 时间：2023.5.17
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)   //二分,可以忽略
    {
        for (int i = gap; i < size; i++)   //O(n)
        {
            int cur = arr[i];
            int j = i - gap;
            for (; j >= 0; j -= gap)   
            {
                if (arr[j] <= cur)
                    break;
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = cur;
        }
    }
}

int main()
{
    srand(time(nullptr));
    int arr[10];

    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 100 + 1;

    for (int ele : arr)
        cout << ele << " ";

    shellSort(arr, 10);

    cout << "\n*******希尔排序后*********\n";

    for (int ele : arr)
        cout << ele << " ";
}