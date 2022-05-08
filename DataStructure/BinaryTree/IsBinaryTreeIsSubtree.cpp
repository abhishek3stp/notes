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

void storeInorder(node *root, char arr[], int &i)
{
    if (root == NULL)
        return;
    storeInorder(root->left, arr, i);
    arr[i++] = root->data + '0';
    storeInorder(root->right, arr, i);
}

void storePreOrder(node *root, char arr[], int &i)
{
    if (root == NULL)
        return;
    arr[i++] = root->data + '0';
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}

bool isBinaryTreeIsSubtree(node *root1, node *root2)
{
    if (root2 == NULL)
        return true;
    if (root1 == NULL)
        return false;

    int n = 0, m = 0;
    char Inroot1[100], Inroot2[100];
    storeInorder(root1, Inroot1, n);
    storeInorder(root2, Inroot2, m);
    Inroot1[n] = '\0', Inroot2[m] = '\0';

    if (strstr(Inroot1, Inroot2) == NULL)
        return false;

    n = 0, m = 0;
    char Preroot1[100], Preroot2[100];
    storePreOrder(root1, Preroot1, n);
    storePreOrder(root2, Preroot2, m);
    Preroot1[n] = '\0', Preroot2[m] = '\0';

    if (strstr(Preroot1, Preroot2) != NULL)
        return true;
}

int main()
{
    node *root1 = newNode(1);
    insert(root1, 2);
    insert(root1, 3);
    insert(root1, 4);
    insert(root1, 5);
    insert(root1, 6);
    insert(root1, 7);
    node *root2 = newNode(2);
    insert(root2, 4);
    insert(root2, 5);
    cout << isBinaryTreeIsSubtree(root1, root2);
    return 0;
}
