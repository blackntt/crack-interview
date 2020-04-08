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
int getHeight(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int heigth = 1;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (leftHeight == -1 || rightHeight == -1)
    {
        return -1;
    }
    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }
    heigth = max(leftHeight + 1, rightHeight + 1);
    return heigth;
}

int main()
{
    TreeNode<int> *a = new TreeNode<int>();
    a->data = 1;
    TreeNode<int> *b = new TreeNode<int>();
    b->data = 2;
    TreeNode<int> *c = new TreeNode<int>();
    c->data = 3;
    a->left =b;
    a->right =c;
    cout << getHeight(a);

    return 0;
}