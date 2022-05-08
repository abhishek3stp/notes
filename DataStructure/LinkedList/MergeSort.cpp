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

node *middleNode(node *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *mergeSort(node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    node *mid = middleNode(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    node *c = sortedMerge(a, b);
    return c;
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
    node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 15);
    insertAtHead(head, 1);
    insertAtHead(head, 5);
    insertAtHead(head, 8);
    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    printList(head);
    head = mergeSort(head);
    printList(head);
}
