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

node *lca(node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a or root->data == b)
        return root;

    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if (leftans != NULL and rightans != NULL)
        return root;

    if (leftans != NULL)
        return leftans;

    return rightans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    root->left->left->right = new node(7);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->left->left->right->left = new node(10);
    root->left->left->right->right = new node(11);

    cout << lca(root, 10, 5)->data << endl;
    return 0;
}
