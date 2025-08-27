/*******************************************************
 描述：冒泡、选择、插入、希尔排序性能对比
 作者：周康
 时间：2023.9.10
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
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
        if (!flag)
            return;
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int k = i;
        int min = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                k = j;
            }
        }

        if (k != i)
        {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}

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

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2) // 二分,可以忽略
    {
        for (int i = gap; i < size; i++) // O(n)
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
    const int COUNT = 100000;
    int *arr1 = new int[COUNT];
    int *arr2 = new int[COUNT];
    int *arr3 = new int[COUNT];
    int *arr4 = new int[COUNT];

    srand(time(nullptr));

    for (int i = 0; i < COUNT; i++)
    {
        int val = rand() % COUNT;
        arr1[i] = val;
        arr2[i] = val;
        arr3[i] = val;
        arr4[i] = val;
    }

    auto start1 = chrono::high_resolution_clock::now();
    bubbleSort(arr1, COUNT);
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    cout << "冒泡排序执行时间: " << duration1.count() / 1000.0 << " 毫秒" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    selectionSort(arr2, COUNT);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    cout << "选择排序执行时间: " << duration2.count() / 1000.0 << " 毫秒" << endl;

    auto start3 = chrono::high_resolution_clock::now();
    insertionSort(arr3, COUNT);
    auto end3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
    cout << "插入排序执行时间: " << duration3.count() / 1000.0 << " 毫秒" << endl;

    auto start4 = chrono::high_resolution_clock::now();
    shellSort(arr4, COUNT);
    auto end4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::microseconds>(end4 - start4);
    cout << "希尔排序执行时间: " << duration4.count() / 1000.0 << " 毫秒" << endl;

    return 0;
}
