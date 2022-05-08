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

class LinkedList
{
public:
    node *head;
    node *tail;
};

void insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return;
    }
    if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
    return;
}

LinkedList flatten(node *root)
{
    LinkedList l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    if (root->left == NULL)
    {
        LinkedList right = flatten(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }
    if (root->right == NULL)
    {
        LinkedList left = flatten(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    }

    LinkedList left = flatten(root->left);
    LinkedList right = flatten(root->right);
    left.tail->right = root;
    root->right = right.head;
    l.head = left.head;
    l.tail = right.tail;
    return l;
}

int main()
{
    node *root = NULL;
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 2);
    insert(root, 3);
    insert(root, 1);
    LinkedList l = flatten(root);
    node *temp = l.head;
    while (temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->right;
    }
}
