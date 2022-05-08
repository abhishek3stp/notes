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

void printKsumPaths(node *root, vector<int> &arr, int k)
{
    if (root == NULL)
        return;
    arr.push_back(root->data);
    printKsumPaths(root->left, arr, k);
    printKsumPaths(root->right, arr, k);
    int sum = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        sum += arr[i];
        if (sum == k)
        {
            for (int j = i; j < arr.size(); j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
    arr.pop_back();
}

int main()
{
    node *root = newNode(1);
    insert(root, 3);
    insert(root, -1);
    insert(root, 2);
    insert(root, 1);
    insert(root, 4);
    insert(root, 5);
    insert(root, 8);
    insert(root, -1);
    insert(root, 1);
    insert(root, 1);
    insert(root, 2);
    insert(root, 6);
    vector<int> arr;
    printKsumPaths(root, arr, 5);
    return 0;
}
