#include <iostream>
#include <cmath>
using namespace std;

/*******************************************
 * 素数：大于1的自然数且只有1和本身两个约数
 * 功能：打印3000以内的素数
 ********************************************/

// 判断一个数字是否是素数
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    // 只需要检查到平方根
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 0; i <= 3000; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;
    return 0;
}