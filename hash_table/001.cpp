/*******************************************************
 描述：线性探测哈希表的实现
 作者：周康
 时间：2023.11.11
 思路:
       用数组实现，在堆区开辟内存，key可以重复 -> unordered_multimap
       桶：值 & 状态（枚举变量）
       使用的hash函数：除留余数法
       增加：1.通过哈希函数计算数据存放的位置；
             2.该位置空闲直接存储，完；
             3.该位置占用，从当前位置往后找。
       查询：1.通过哈希函数计算数据存放位置，从该位置取值
             2.该值==要查询的值，找到；
             3.该值！=要查询的值（之前往此位置放元素的时候发生hash冲突），往后
               遍历   注意：遍历到一个从未使用的位置就不用遍历了，不存在
       删除：1.hash函数计算存放位置，判断State，取值==要删除的，就改state；
             2.该值！=要删的，之前发生过哈希冲突，往后遍历，找到改状态，遇到
               STATE_UNUSE结束，因为值不存在
*******************************************************/
#include <iostream>
using namespace std;

// 桶的状态
enum State
{
    STATE_UNUSE, // 从未使用过的桶
    STATE_USING, // 正在使用的桶
    STATE_DEL,   // 元素被删除过的桶
};

// 桶的结构体
struct Bucket
{
    Bucket(int key = 0, State state = STATE_UNUSE)
        : key_(key), state_(state) {}

    int key_;     // 存储的数据
    State state_; // 桶的状态
};

// 线性探测哈希表类    
class HashTable
{
public:
    HashTable(int size=primes_[0],double load_factor=0.75)
        :use_bucket_num_(0),load_factor_(load_factor),prime_idx_(0)
        {
            // 把用户传入的size调整到最近比较大的素数上
            if(size!=primes_[0])
            {
                for (; prime_idx_ < PRIME_SIZE;prime_idx_++)
                {
                    if(primes_[prime_idx_]>size)
                        break;
                }
                // 用户传入的size值过大，已经超过最后一个素数，那就取最大
                if(prime_idx_==PRIME_SIZE)
                    prime_idx_--;
            }
            table_size_ = primes_[prime_idx_];
            table_ = new Bucket[table_size_];
        }

        ~HashTable()
        {
            delete[] table_;
            table_ = nullptr;
        }

public:
    //插入元素
    bool insert(int key)
    {
        //考虑扩容
        double factor = use_bucket_num_*1.0 / table_size_;
        cout << "factor:" << factor << endl;

        if(factor>load_factor_)
        {
            expand();
        }

        int idx = key % table_size_; // hash funcion

        int i = idx;
        do
        {
            if (table_[i].state_ != STATE_USING)
            {
                table_[i].state_ = STATE_USING;
                table_[i].key_ = key;
                use_bucket_num_++;
                return true;
            }
            i = (i + 1) % table_size_;
        } while (i != idx);

        return false;
    }

    //删除元素
    bool erase(int key)
    {
        int idx = key % table_size_;
        int i = idx;
        do
        {
            if (table_[i].state_ == STATE_USING && table_[i].key_==key)
            {
                table_[i].state_ = STATE_DEL;
                use_bucket_num_--;
            }
            i = (i + 1) % table_size_;
        } while (table_[i].state_!=STATE_UNUSE && i!=idx);

        return true;
    }

    // 查询(只关心有无，也可以是个数int，按需设计)
    bool find(int key)
    {
        int idx = key % table_size_;
        int i = idx;
        do
        {
            if (table_[i].state_ == STATE_USING && table_[i].key_==key)
                return true;
            
            i = (i + 1) % table_size_;
        } while (table_[i].state_!=STATE_UNUSE && i!=idx);

        return false;
    }

private:
    Bucket *table_;  // 指向动态开辟的哈希表
    int table_size_; // 当前长度
    int use_bucket_num_;  //已经使用的桶的个数
    double load_factor_;  //哈希表的装载因子

    static const int PRIME_SIZE = 10; // 素数表的大小
    static int primes_[PRIME_SIZE];   // 素数表
    int prime_idx_;                    // 当前使用的素数下标

private:
    // 扩容操作
    void expand()
    {
        ++prime_idx_;
        if (prime_idx_ == PRIME_SIZE)
        {
            throw "HashTable is too large,can not expand anymore!";
        }

        Bucket *newTable = new Bucket[primes_[prime_idx_]];
        for (int i = 0; i < table_size_; i++)
        {
            if (table_[i].state_ == STATE_USING) // 旧表有效的数据，重新哈希放新表
            {
                int idx = table_[i].key_ % primes_[prime_idx_];

                int k= idx;
                do
                {
                    if(newTable[k].state_!=STATE_USING)
                    {
                        newTable[k].state_ = STATE_USING;
                        newTable[k].key_ = table_[i].key_;
                        break;
                    }
                    k = (k + 1) % primes_[prime_idx_];
                } while (k != idx);
            }
        }

        delete[] table_;
        table_ = newTable;
        table_size_ = primes_[prime_idx_];
    }
};

int HashTable::primes_[PRIME_SIZE]{3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773};

int main()
{

    HashTable ht;
    ht.insert(21);
    ht.insert(32);
    ht.insert(14);
    ht.insert(15);

    ht.insert(19);

    cout << ht.find(14) << endl;
    cout << ht.find(141) << endl;

    ht.erase(14);
    cout << ht.find(14) << endl;


    return 0;
}