/*******************************************************
 描述：插入排序
 时间复杂度：最坏&平均：O(n^2)   最好：O(n)
 空间复杂度：O(1)
 排序稳定性：稳定
 思路：前面的序列算排列好的，每一轮关注排列好的序列的后一个元素m
       的应有位置，对排好的序列由后往前遍历，找到<=m就break，不是
       就后移1位。最后将m放在找到元素的后一位（因为每次比较后移了，
       所以不会覆盖）
 作者：周康
 时间：2023.5.10
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int cur = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] <= cur)
                break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = cur;
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

    insertionSort(arr, 10);

    cout << "\n*******选择排序后*********\n";

    for (int ele : arr)
        cout << ele << " ";
}