/*******************************************************
 描述：整型数组，把偶数调整到数组左边，把奇数调整到数组右边。
 思路：双指针
 作者：周康
 时间：2023.7.10
*******************************************************/
#include <iostream>
#include <time.h>
using namespace std;

void adjustArray(int arr[], int size)
{
    int *p = arr;
    int *q = arr + size - 1;

    while (p < q)
    {
        // p -> 找奇数
        if ((*p & 0x1) == 0) // 位操作，元素是偶数
        {
            p++;
            continue;
        }

        // <- q 找偶数
        if ((*q & 0x1) == 1) // 元素是奇数
        {
            q--;
            continue;
        }

        // 到这里了，p找到了奇数，q找到了偶数
        int tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
}

int main()
{
    int arr[10]{0};
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int em : arr)
        cout << em << " ";

    cout << "\n*************处理后***************\n";

    adjustArray(arr, 10);
    for (int em : arr)
        cout << em << " ";
    cout << endl;

    return 0;
}