#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
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

void leftView(node *root, int level)
{
    if (root == NULL)
        return;
    static int maxLevel = 0;
    if (level >= maxLevel)
    {
        cout << root->data << " ";
        maxLevel++;
    }
    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
}

void rightView(node *root, int level)
{
    if (root == NULL)
        return;
    static int maxLevel = 0;
    if (level >= maxLevel)
    {
        cout << root->data << " ";
        maxLevel++;
    }
    rightView(root->right, level + 1);
    rightView(root->left, level + 1);
}

void topView(node *root)
{
    queue<node *> q;
    q.push(root);
    map<int, int> m;
    root->height = 0;
    while (q.size())
    {
        node *temp = q.front();
        q.pop();
        int height = temp->height;
        if (m.count(height) == 0)
            m[height] = temp->data;
        if (temp->left)
        {
            temp->left->height = height - 1;
            q.push(temp->left);
        }
        if (temp->right)
        {
            temp->right->height = height + 1;
            q.push(temp->right);
        }
    }
    for (auto it : m)
        cout << it.second << " ";
}

void bottomView(node *root)
{
    queue<node *> q;
    q.push(root);
    map<int, int> m;
    root->height = 0;
    while (q.size())
    {
        node *temp = q.front();
        q.pop();
        int height = temp->height;
        m[height] = temp->data;
        if (temp->left)
        {
            temp->left->height = height - 1;
            q.push(temp->left);
        }
        if (temp->right)
        {
            temp->right->height = height + 1;
            q.push(temp->right);
        }
    }
    for (auto it : m)
        cout << it.second << " ";
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
    // leftView(root, 0);
    // rightView(root, 0);
    // topView(root);
    // bottomView(root);
    return 0;
}
