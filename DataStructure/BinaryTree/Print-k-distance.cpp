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

void printkdistanceDown(node *root, int k)
{
    if (root == NULL or k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << ", ";
        return;
    }
    printkdistanceDown(root->left, k - 1);
    printkdistanceDown(root->right, k - 1);
    return;
}

int printAtkdistance(node *root, node *target, int k)
{
    if (root == NULL)
        return -1;

    if (root == target)
    {
        printkdistanceDown(root, k);
        return 0;
    }

    int dl = printAtkdistance(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
            cout << root->data << ", ";
        else
            printkdistanceDown(root->right, k - 2 - dl);
        return dl + 1;
    }

    int dr = printAtkdistance(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << ", ";
        else
            printkdistanceDown(root->left, k - 2 - dr);
        return dr + 1;
    }
    return -1;
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

    node *target = root->left->left;
    printAtkdistance(root, target, 2);
    return 0;
}
