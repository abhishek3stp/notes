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

int kthNodeEnd(node *head, int k)
{
    node *current = head;
    for (int i = 0; i < k; i++)
    {
        if (current == NULL)
            return -1;
        current = current->next;
    }

    while (current != NULL)
    {
        head = head->next;
        current = current->next;
    }
    return head->data;
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
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printList(head);
    cout << kthNodeEnd(head, 3) << endl;
}
