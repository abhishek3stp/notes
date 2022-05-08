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

int search(node *root, int key, int level)
{
    if (root == NULL)
        return -1;

    if (root->data == key)
        return level;

    int left = search(root->left, key, level + 1);
    if (left != -1)
        return left;

    return search(root->right, key, level + 1);
}

int minDistance(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);

    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);
    return l1 + l2;
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

    cout << minDistance(root, 7, 9) << endl;
    return 0;
}
