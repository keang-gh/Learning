/*******************************************************
 描述：实现BST树：插入（非递归）、删除(非递归)、查找（非递归）、
                 前/中/后/层序遍历（递归）、
                 求层数（递归）、求节点个数（递归）、
                 插入（递归）、删除（递归）、查找（递归）
                 前/中/后/层序遍历（非递归）
 作者：周康
 时间：2024.7.10整合完
*******************************************************/
#include <iostream>
#include <functional>
#include <stack>
using namespace std;

template <typename T, typename Comp = less<T>>
class BST
{
public:
    BST() : root_(nullptr) {}
    ~BST() {}

    // **********非递归插入操作,插完都成叶子节点**********
    void n_insert(const T &val)
    {
        // 情况1：树为空，就生成根节点
        if (root_ == nullptr)
        {
            root_ = new Node(val);
            return;
        }

        // 情况2：如果树不为空，搜索合适的插入位置，记录父节点的位置
        Node *parent = nullptr;
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                return;
            }
            else if (comp_(cur->data_, val)) // 大于关系
            {
                parent = cur;
                cur = cur->right_;
            }
            else
            {
                parent = cur;
                cur = cur->left_;
            }
        }

        // 把新节点插入到parent节点的孩子上
        if (comp_(val, parent->data_))
            parent->left_ = new Node(val);
        else
            parent->right_ = new Node(val);
    }

    // ***********递归插入操作******************
    void insert(const T &val)
    {
        root_ = insert(root_, val);
    }

    // ********非递归删除操作********
    void n_remove(const T &val)
    {
        // 树空
        if (root_ == nullptr)
            return;

        // 搜索待删除节点
        Node *parent = nullptr;
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                break; // 找到删除节点
            }
            else if (comp_(cur->data_, val))
            {
                parent = cur;
                cur = cur->right_;
            }
            else
            {
                parent = cur;
                cur = cur->left_;
            }
        }

        // 出来有2种情况，1是找到break，2是没找到
        if (cur == nullptr)
            return;

        // 先处理情况3：删除的节点有2孩子 -> 删除前驱节点，转化成情况1，2
        if (cur->left_ != nullptr && cur->right_ != nullptr)
        {
            parent = cur;
            Node *pre = cur->left_;
            while (pre->right_ != nullptr)
            {
                parent = pre;
                pre = pre->right_;
            }
            cur->data_ = pre->data_;
            cur = pre; // 让cur指向前驱节点，转化成1 or 2（叶子节点 or 只有1孩子）
        }

        // cur指向删除节点，parent指向其父节点，统一处理情况1 or 2
        Node *child = cur->left_;
        if (child == nullptr)
        {
            child = cur->right_;
        }

        if (parent == nullptr) // 特殊情况 表示删除的是根节点
        {
            root_ = child;
        }
        else
        {
            // 当待删除节点的孩子（nullptr或不空）写入其父节点相应地址域中
            if (parent->left_ == cur)
            {
                parent->left_ = child;
            }
            else
            {
                parent->right_ = child;
            }
        }

        delete cur; // 删除当前节点
    }

    //*********递归删除操作**************** 
    void remove(const T &val)
    {
        root_ = remove(root_, val);
    }

    //************非递归查询操作**************
    bool n_find(const T &val)
    {
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                return true;
            }
            else if (comp_(cur->data_, val))
            {
                cur = cur->right_;
            }
            else
            {
                cur = cur->left_;
            }
        }
        return false;
    }

    //*************递归查询操作***************
    bool query(const T &val)
    {
        return nullptr!=query(root_, val);
    }

    //************递归前序遍历**************
    void preOrder()
    {
        cout << "前序遍历[递归]:\n";
        preOrder(root_);
        cout << endl;
    }

    //*********非递归前序遍历***************
    void n_preOrder()
    {
        cout << "前序遍历[非递归]:\n";
        if(root_==nullptr)
        {
            return;
        }
        stack<Node *> s;
        s.push(root_);
        while(!s.empty())
        {
            Node *top = s.top();
            s.pop();

            cout << top->data_ << " ";

            if(top->right_!=nullptr)
            {
                s.push(top->right_);
            }

            if(top->left_!=nullptr)
            {
                s.push(top->left_);
            }
        }
        cout << endl;
    }

    //************递归中序遍历**************
    void inOrder()
    {
        cout << "中序遍历[递归]:\n";
        inOrder(root_);
        cout << endl;
    }

    //*********非递归中序遍历***************
    void n_inOrder()
    {
        cout << "中序遍历[非递归]:\n";
        if(root_==nullptr)
        {
            return;
        }
        stack<Node *> s;
        Node *cur = root_;
        while(cur!=nullptr)
        {
            s.push(cur);
            cur = cur->left_;
        }

        while(!s.empty())
        {
            Node *top = s.top();
            s.pop();

            cout << top->data_ << " ";

            cur = top->right_;
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left_;
            }
        }
        cout << endl;
    }

    //************递归后序遍历**************
    void postOrder()
    {
        cout << "后序遍历[递归]:\n";
        postOrder(root_);
        cout << endl;
    }

    //************递归层序遍历**************
    void levelOrder()
    {
        cout << "层序遍历[递归]:\n";
        int h = height();  //树的层数
        for (int i = 0; i < h;++i)
        {
            levelOrder(root_, i);  //递归调用树的层数
        }
        cout << endl;
    }

    //递归求二叉树层数
    int height()
    {
        return height(root_);
    }

    //递归求二叉树节点个数
    int number()
    {
        return number(root_);
    }

private:
    // 节点定义
    struct Node
    {
        Node(T data = T{}) : data_(data), left_(nullptr), right_(nullptr) {}
        T data_;        // 节点的数据域
        Node *left_;    // 节点的左孩子域
        Node *right_;   // 节点的右孩子域
    };
    Node *root_;   // 指向BST树的根节点
    Comp comp_;    // 定义一个函数对象    前后小于为true

    // 递归前序遍历的实现
    void preOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data_ << " ";
            preOrder(node->left_);
            preOrder(node->right_);
        }
    }

    // 递归中序遍历的实现
    void inOrder(Node *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left_);
            cout << node->data_ << " ";
            inOrder(node->right_);
        }
    }

    // 递归后序遍历的实现
    void postOrder(Node *node)
    {
        if (node != nullptr)
        {
            postOrder(node->left_);
            postOrder(node->right_);
            cout << node->data_ << " ";
        }
    }

    //递归层序遍历的实现
    void levelOrder(Node *node,int i)
    {
        if(node==nullptr)
            return;
        
        if(i==0)
        {
            cout << node->data_ << " ";
            return;
        }

        levelOrder(node->left_, i - 1);
        levelOrder(node->right_, i - 1);
    }

    //递归求二叉树层数,求node为根节点的子树的高度
    int height(Node* node)
    {
        if(node==nullptr)
        {
            return 0;
        }
        int left = height(node->left_);
        int right = height(node->right_);
        return left > right ?: left + 1,right + 1;
    }

    //递归求二叉树节点个数
    int number(Node* node)
    {
        if(node==nullptr)
            return 0;
        int left = number(node->left_);
        int right = number(node->right_);
        return left + right + 1;
    }

    // 递归插入操作
    Node* insert(Node * node,const T& val)
    {
        if(node==nullptr)
        {
            // 递归结束，找到插入val的位置，生成新节点并返回其节点
            return new Node(val);
        }

        if(node->data_==val)
        {
            return node;
        }
        else if(comp_(node->data_,val))
        {
            node->right_=insert(node->right_, val);
            return node;
        }
        else
        {
            node->left_ = insert(node->left_, val);
            return node;
        }
    }

    // 递归查询操作实现
    Node* query(Node *node,const T &val)
    {
        if(node==nullptr)
            return nullptr;

        if(node->data_==val)
            return node;
        else if(comp_(node->data_,val))
            return query(node->right_, val);
        else
            return query(node->left_, val);
    }

    // 递归删除操作实现
    Node* remove(Node *node,const T &val)
    {
        if(node==nullptr)
            return nullptr;
        
        if(node->data_==val)  // 找到待删除节点
        {
            // 情况3，有2孩子
            if(node->left_!=nullptr && node->right_!=nullptr)
            {
                // 找前驱节点
                Node *pre = node->left_;
                while(pre->right_!=nullptr)
                {
                    pre = pre->right_;
                }
                node->data_ = pre->data_;
                // 通过递归直接删除前驱节点
                node->left_ = remove(node->left_, pre->data_);
            }
            else    // 情况1 & 情况2
            {
                if(node->left_!=nullptr)   
                {
                    // 删除节点后，把非空的左孩子返回，回溯时更新其父节点地址域
                    Node *left = node->left_;
                    delete node;
                    return left;
                }
                else if(node->right_!=nullptr)
                {
                    // 删除节点后，把非空的左孩子返回，回溯时更新其父节点地址域
                    Node *right = node->right_;
                    delete node;
                    return right;
                }
                else   
                {
                    // 删除的是叶子节点，回溯时更新其父节点的地址域为nullptr
                    delete node;
                    return nullptr;
                }
            }
        }
        else if (comp_(node->data_, val))
        {
            node->right_ = remove(node->right_, val);
        }
        else
        {
            node->left_ = remove(node->left_, val);
        }
        return node;  // 把当前节点返回给父节点，更新父节点相应的地址域
    }
};

int main()
{
    //int arr[]{1, 3, 4, 5, 7, 8, 10};
    int arr[]{58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78};
    BST<int> bst;

    for (int ele : arr)
    {
        //bst.n_insert(ele);
        bst.insert(ele);
    }
    // cout << bst.query(1999) << endl;
    // bst.insert(1999);
    // cout << bst.query(1999) << endl;


    // cout << bst.n_find(222) << endl; // 0
    // cout << bst.n_find(7) << endl;   // 1
    // cout << bst.n_find(76) << endl;  // 0
    // cout << bst.n_find(3) << endl;   // 1
    // bst.n_remove(3);
    // cout << bst.n_find(3) << endl;   // 0
    // bst.n_insert(3);
    // cout << bst.n_find(3) << endl;   // 1

    bst.inOrder();
    bst.n_inOrder();

    // bst.postOrder();
    // bst.levelOrder();
    // cout << bst.height() << endl;;
    // cout << bst.number() << endl;

    return 0;
}