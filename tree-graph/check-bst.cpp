#include <iostream>
using namespace std;
template <class T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};
template <class T>
bool checkBST(TreeNode<T> *root,T max, T min)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data>max || root->data<min)
        return false;
    bool leftStatus = checkBST<T>(root->left,root->data,INT_MIN);
    bool rightStatus = checkBST<T>(root->right,INT_MAX, root->data);
    if(!leftStatus || !rightStatus)
        return false;
    if(root->left==nullptr && root->right!=nullptr)
        return false;
    return true;
}

int main()
{
    TreeNode<int> *a = new TreeNode<int>();
    a->data = 1;
    TreeNode<int> *b = new TreeNode<int>();
    b->data = 2;
    TreeNode<int> *c = new TreeNode<int>();
    c->data = 3;
    TreeNode<int> *d = new TreeNode<int>();
    d->data = 4;
    b->left =a;
    b->right =c;
    cout << checkBST<int>(b,INT_MAX,INT_MIN);
    return 0;
}