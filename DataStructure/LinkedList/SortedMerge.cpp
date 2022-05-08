#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *newNode = new node(data);
    newNode->next = head;
    head = newNode;
    return;
}

node *sortedMerge(node *a, node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    node *result = NULL;
    if (a->data < b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *a = NULL;
    insertAtHead(a, 40);
    insertAtHead(a, 15);
    insertAtHead(a, 10);
    insertAtHead(a, 5);
    printList(a);
    node *b = NULL;
    insertAtHead(b, 20);
    insertAtHead(b, 3);
    insertAtHead(b, 2);
    printList(b);
    node *c = sortedMerge(a, b);
    printList(c);
}
