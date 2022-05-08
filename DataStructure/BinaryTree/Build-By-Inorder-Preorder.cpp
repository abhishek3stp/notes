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

void postorder(node *temp)
{
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << ", ";
}

node *buildTree(int pre[], int in[], int s, int e)
{
    static int i = 0;

    if (s > e)
        return NULL;

    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;

    root->left = buildTree(pre, in, s, index - 1);
    root->right = buildTree(pre, in, index + 1, e);
    return root;
}

int main()
{
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int n = sizeof(in) / sizeof(int);
    node *root = buildTree(pre, in, 0, n - 1);
    postorder(root);
    return 0;
}
