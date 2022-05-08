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

void preorder(node *temp)
{
    if (temp == NULL)
        return;

    cout << temp->data << ", ";
    preorder(temp->left);
    preorder(temp->right);
}

int sumtree(node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL and root->right == NULL)
        return root->data;

    int temp = root->data;
    root->data = sumtree(root->left) + sumtree(root->right);
    return temp + root->data;
}

int main()
{
    node *root = new node(8);
    root->left = new node(10);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->right->left = new node(14);
    root->left->right->left = new node(9);
    root->left->right->right = new node(7);
    root->right->left->left = new node(13);

    sumtree(root);
    preorder(root);
    return 0;
}
