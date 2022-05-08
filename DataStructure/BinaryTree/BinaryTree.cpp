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

int size(node *temp)
{
    if (temp == NULL)
        return 0;

    int l_size = size(temp->left);
    int r_size = size(temp->right);
    return l_size + r_size + 1;
}

int sum(node *temp)
{
    if (temp == NULL)
        return 0;

    int l_sum = sum(temp->left);
    int r_sum = sum(temp->right);
    return l_sum + r_sum + temp->data;
}

int height(node *temp)
{
    if (temp == NULL)
        return 0;

    int l_height = height(temp->left);
    int r_height = height(temp->right);
    return 1 + max(l_height, r_height);
}

int maxNode(node *temp)
{
    if (temp == NULL)
        return INT_MIN;

    int l_max = maxNode(temp->left);
    int r_max = maxNode(temp->right);
    return max(l_max, max(temp->data, r_max));
}

int diameter(node *temp)
{
    if (temp == NULL)
        return 0;

    int l_dia = diameter(temp->left);
    int r_dia = diameter(temp->right);
    int dia = height(temp->left) + height(temp->right) + 1;
    return max(dia, max(l_dia, r_dia));
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair fastDaimter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastDaimter(root->left);
    Pair right = fastDaimter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height + 1, max(left.diameter, right.diameter));
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

    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << height(root) << endl;
    cout << maxNode(root) << endl;
    cout << diameter(root) << endl;
    cout << fastDaimter(root).diameter << endl;
    return 0;
}
