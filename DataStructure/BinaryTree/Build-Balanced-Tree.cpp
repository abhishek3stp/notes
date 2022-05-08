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

node *buildTree(int arr[], int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildTree(arr, s, mid - 1);
    root->right = buildTree(arr, mid + 1, e);

    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    node *root = buildTree(arr, 0, n - 1);
    preorder(root);
    return 0;
}
