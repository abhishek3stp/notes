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

class Pair
{
public:
    int height;
    bool balance;
};

Pair isBalacnce(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }
    Pair left = isBalacnce(root->left);
    Pair right = isBalacnce(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 and left.balance and right.balance)
        p.balance = true;
    else
        p.balance = false;

    return p;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);

    cout << isBalacnce(root).balance << endl;
    return 0;
}
