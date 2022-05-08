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

void insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return;
    }
    if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
    return;
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
}

bool search(node *root, int data)
{
    if (root == NULL)
        return false;

    if (data == root->data)
        return true;

    if (data <= root->data)
        return search(root->left, data);

    else
        return search(root->right, data);
}

node *deleteNode(node *root, int data)
{
    if (root == NULL)
        return NULL;

    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
    else
    {
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *next = root->right;
        while (next->left != NULL)
            next = next->left;

        root->data = next->data;
        root->right = deleteNode(root->right, next->data);
        return root;
    }
}

int main()
{
    node *root = NULL;
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 2);
    insert(root, 3);
    insert(root, 1);
    cout << search(root, 5) << endl;
    root = deleteNode(root, 5);
    inorder(root);
}
