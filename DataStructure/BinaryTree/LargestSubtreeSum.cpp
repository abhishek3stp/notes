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

int largestSubtreeSumUtil(node *root, int &sum)
{
    if (root == NULL)
        return 0;
    int CurrSum = root->data + largestSubtreeSumUtil(root->left, sum) + largestSubtreeSumUtil(root->right, sum);
    sum = max(CurrSum, sum);
    return CurrSum;
}

int largestSubtreeSum(node *root)
{
    if (root == NULL)
        return 0;
    int sum = INT_MIN;
    largestSubtreeSumUtil(root, sum);
    return sum;
}

int main()
{
    node *root = newNode(1);
    insert(root, -2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, -6);
    insert(root, 2);
    cout << largestSubtreeSum(root);
    return 0;
}
