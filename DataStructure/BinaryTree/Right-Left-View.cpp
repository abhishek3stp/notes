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

void rightView(node *root, int level, int &maxlevel)
{
    if (root == NULL)
        return;

    if (maxlevel < level)
    {
        cout << root->data << ", ";
        maxlevel = level;
    }

    rightView(root->right, level + 1, maxlevel);
    rightView(root->left, level + 1, maxlevel);
}

void leftView(node *root, int level, int &maxlevel)
{
    if (root == NULL)
        return;

    if (maxlevel < level)
    {
        cout << root->data << ", ";
        maxlevel = level;
    }

    leftView(root->left, level + 1, maxlevel);
    leftView(root->right, level + 1, maxlevel);
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

    int maxlevel = -1;
    rightView(root, 0, maxlevel);
    // leftView(root, 0, maxlevel);
    return 0;
}
