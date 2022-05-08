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

void preorder(node *temp)
{
    if (temp == NULL)
        return;

    cout << temp->data << ", ";
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ", ";
    inorder(temp->right);
}

void postorder(node *temp)
{
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << ", ";
}

void preorderWR(node *temp)
{
    if (temp == NULL)
        return;

    stack<node *> s;
    s.push(temp);

    while (!s.empty())
    {
        node *temp = s.top();
        cout << temp->data << ", ";
        s.pop();

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void inorderWR(node *temp)
{
    if (temp == NULL)
        return;

    stack<node *> s;

    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        node *temp = s.top();
        cout << temp->data << ", ";
        s.pop();

        if (temp->right != NULL)
        {
            temp = temp->right;
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
        }
    }
}

void postorderWR(node *temp)
{
    if (temp == NULL)
        return;

    stack<node *> s1, s2;
    s1.push(temp);

    while (!s1.empty())
    {
        node *temp = s1.top();
        s2.push(temp);
        s1.pop();

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << ", ";
        s2.pop();
    }
}

void levelorderWR(node *temp)
{
    if (temp == NULL)
        return;

    queue<node *> q;
    q.push(temp);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);

        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
    }
}

int height(node *temp)
{
    if (temp == NULL)
        return 0;

    int l_height = height(temp->left);
    int r_height = height(temp->right);
    return 1 + max(l_height, r_height);
}

void kthlevel(node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    kthlevel(root->left, k - 1);
    kthlevel(root->right, k - 1);
}

void levelorder(node *root)
{
    for (int i = 1; i <= height(root); i++)
    {
        kthlevel(root, i);
        cout << endl;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    preorder(root);
    preorderWR(root);
    inorder(root);
    inorderWR(root);
    postorder(root);
    postorderWR(root);
    levelorder(root);
    levelorderWR(root);
    return 0;
}
