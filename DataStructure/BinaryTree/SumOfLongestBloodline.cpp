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

void sumOfLongRootToLeaf(node* root, int sum, int len, int& maxLen, int& maxSum) 
{ 
    if (root == NULL)
    {
        if (maxLen < len)
        { 
            maxLen = len; 
            maxSum = sum; 
        }
        else if (maxLen == len && maxSum < sum) 
            maxSum = sum; 
        return; 
    } 
    sumOfLongRootToLeaf(root->left, sum + root->data, len + 1, maxLen, maxSum);  
    sumOfLongRootToLeaf(root->right, sum + root->data, len + 1, maxLen, maxSum); 
} 

int sumOfLongestBloodline(node* root) 
{
    if (root == NULL) 
        return 0; 
    int maxSum = INT_MIN, maxLen = 0; 
    sumOfLongRootToLeaf(root, 0, 0, maxLen, maxSum); 
    return maxSum; 
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
    cout << sumOfLongestBloodline(root);
    return 0;
}
