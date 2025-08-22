/*******************************************************
 描述：在数组中原地移除所有等于给定值的元素，并返回新数组的长度（力扣27）
 思路：双指针
 作者：周康
 时间：2023.7
*******************************************************/
#include <iostream>
using namespace std;

int removeElement(int *nums, int nums_size, int val)
{
    int *p = nums;
    int *q = nums + nums_size - 1;

    while (p <= q)
    {
        if (*q == val)
        {
            q--;
            continue;
        }

        if (*p == val)
        {
            *p = *q;
            q--;
        }
        else
        {
            p++;
        }
    }
    return p - nums;
}

int main()
{
    int nums1[]{1, 2, 3, 4, 3, 5, 7, 3, 5};

    cout << "************给定的数组********************\n";
    int length1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "原数组元素个数：" << length1 << endl;
    for (int i = 0; i < length1; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << "\n**************移除3元素后*****************\n";
    int length2 = removeElement(nums1, length1, 3);
    cout << "处理后数组元素个数：" << length2 << endl;
    for (int i = 0; i < length2; i++)
    {
        cout << nums1[i] << " ";
    }
}