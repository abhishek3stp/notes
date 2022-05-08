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

node *kReverse(node *head, int k)
{
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;
    while (current != NULL and count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // This code not reverse list less then k
    count = 0;
    node *check = next;
    while (check != NULL and count != k)
    {
        check = check->next;
        count++;
    }
    if (count < k)
        head->next = next;
    else
        head->next = kReverse(next, k);

    return prev;
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
    insertAtHead(head, 9);
    insertAtHead(head, 6);
    insertAtHead(head, 1);
    insertAtHead(head, 5);
    printList(head);
    head = kReverse(head, 3);
    printList(head);
}
