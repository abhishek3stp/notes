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
    int branchSum;
    int maxSum;
};

Pair maxSumPath(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.branchSum = p.maxSum = 0;
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;

    int through_root = max({op1, op2, op3, op4});

    p.branchSum = max({left.branchSum, right.branchSum, 0}) + root->data;
    p.maxSum = max({left.maxSum, right.maxSum, through_root});
    return p;
}

int main()
{
    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(10);
    root->left->left = new node(20);
    root->left->right = new node(1);
    root->right->right = new node(-25);
    root->right->right->left = new node(3);
    root->right->right->right = new node(4);

    cout << maxSumPath(root).maxSum << endl;
    return 0;
}
