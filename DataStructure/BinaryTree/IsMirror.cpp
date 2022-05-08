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

bool isMirror(node* root1, node* root2)
{
    if( root1 == NULL && root2 == NULL)
        return true;
    if( root1 == NULL || root2 == NULL)
        return false;
    return root1->data == root2->data && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

int main()
{
    node *root1 = newNode(1);
    insert(root1, 2);
    insert(root1, 3);
    node* root2 = newNode(1);
    insert(root2, 3);
    insert(root2, 2);
    cout << isMirror(root1, root2);
    return 0;
}
