#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    struct node *left;
    struct node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(node *root)
{
    if (root == NULL)
        return false;
    if (root->left == NULL and root->right == NULL)
        return true;
    return false;
}

bool isSumtree(node *root)
{
    if (root == NULL or isLeaf(root))
        return true;

    int ls, rs;

    if (isSumtree(root->left) and isSumtree(root->right))
    {
        if (root->left == NULL)
            ls = 0;
        else if (isLeaf(root->left))
            ls = root->left->data;
        else
            ls = 2 * (root->left->data);

        if (root->right == NULL)
            rs = 0;
        else if (isLeaf(root->right))
            rs = root->right->data;
        else
            rs = 2 * (root->right->data);

        return root->data == (ls + rs);
    }
    return false;
}

int main()
{
    node *root = new node(26);
    root->left = new node(10);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->right = new node(3);

    cout << isSumtree(root) << endl;
    return 0;
}
