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

bool isBST(node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;

    if (root->data >= min and root->data <= max and isBST(root->left, min, root->data) and isBST(root->right, root->data, max))
        return true;

    return false;
}

int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right = new node(6);
    root->right->right = new node(7);
    cout << isBST(root) << endl;
}
