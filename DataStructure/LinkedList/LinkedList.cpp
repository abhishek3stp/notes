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

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

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

void insertAtEnd(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = new node(data);
    return;
}

void insertAtMiddle(node *&head, int pos, int data)
{
    if (head == NULL or pos == 0)
        insertAtHead(head, data);

    else if (pos > length(head))
        insertAtEnd(head, data);

    else
    {
        node *temp = head;
        for (int i = 1; i <= pos - 1; i++)
            temp = temp->next;
        node *newNode = new node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteHead(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head->next;
    delete head;
    head = temp;
}

void deleteNode(node *&head, int key)
{
    node *temp = head;
    node *prev = NULL;

    if (temp != NULL and temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL and temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
    return;
}

void deleteTail(node *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *prev = head;
    while (prev->next->next != NULL)
        prev = prev->next;

    delete prev->next;
    prev->next = NULL;
}

bool search(node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

bool searchRecursive(node *head, int key)
{
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    else
        return searchRecursive(head->next, key);
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
    insertAtMiddle(head, 3, 8);
    printList(head);
    insertAtEnd(head, 9);
    printList(head);
}
