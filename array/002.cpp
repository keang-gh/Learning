/*******************************************************
 描述：元素逆序问题
 思路：双指针法
 作者：周康
 时间：2023.7
*******************************************************/
#include <iostream>
#include <string.h>
using namespace std;

void reverse(char arr[], int size)
{
    char *p = arr;
    char *q = arr + size - 1;
    while (p < q)
    {
        char tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
}

int main()
{
    char arr[] = "Hello World";
    reverse(arr, strlen(arr));
    cout << arr << endl;

    return 0;
}
