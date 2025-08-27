/*******************************************************
 描述：选择排序
 时间复杂度：最好和最坏都是：O(n^2)
 空间复杂度：O(1)
 排序稳定性：不稳定
 思路：每次在剩下元素中选择最小值元素与当前元素交换
 作者：周康
 时间：2023.5.10
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

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

int main()
{
      srand(time(nullptr));
      int arr[10];

      for (int i = 0; i < 10; i++)
            arr[i] = rand() % 100 + 1; // rand
      

      for (auto ele : arr)
            cout << ele << " ";
      

      cout << "\n***********选择排序后*********\n";
      selectionSort(arr, 10);
      
      for (auto ele : arr)
            cout << ele << " ";
      
      cout << endl;

      return 0;
}
