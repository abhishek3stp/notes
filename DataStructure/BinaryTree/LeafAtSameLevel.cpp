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

bool checkUtil(node *root, int level, int *leafLevel) 
{ 
    if (root == NULL) return true; 
   
    if (root->left == NULL && root->right == NULL) 
    { 
        if (*leafLevel == 0) 
        { 
            *leafLevel = level;
            return true; 
        } 
        return (level == *leafLevel); 
    }  
    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel); 
} 

bool check(node *root) 
{ 
    int level = 0, leafLevel = 0; 
    return checkUtil(root, level, &leafLevel); 
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
    cout << check(root);
    return 0;
}
