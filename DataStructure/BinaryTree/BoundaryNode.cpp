#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(node *root, int key)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = newNode(key);
            break;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL)
        {
            temp->right = newNode(key);
            break;
        }
        else
            q.push(temp->right);
    }
}

void printLeft(node *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        cout << root->data << " ";
        printLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printLeft(root->right);
    }
}

void printRight(node *root)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        printRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        printRight(root->left);
        cout << root->data << " ";
    }
}

void printLeaf(node *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        cout << root->data << " ";
    printLeaf(root->left);
    printLeaf(root->right);
}

void boundaryNode(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printLeft(root->left);
    printLeaf(root->left);
    printLeaf(root->right);
    printRight(root->right);
}

int main()
{
    node *root = newNode(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    boundaryNode(root);
    return 0;
}
