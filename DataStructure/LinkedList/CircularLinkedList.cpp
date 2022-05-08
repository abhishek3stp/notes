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
        head->next = head;
        return;
    }
    node *newNode = new node(data);
    newNode->next = head;
    node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    head = newNode;
    return;
}

node *getNode(node *head, int key)
{
    node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    if (temp->data == key)
        return temp;
    return NULL;
}

void deleteNode(node *&head, int key)
{
    node *del = getNode(head, key);
    if (del == NULL)
        return;
    if (head == del and head->next == head)
    {
        delete del;
        head = NULL;
        return;
    }
    if (head == del)
        head = head->next;

    node *temp = head;
    while (temp->next != del)
        temp = temp->next;

    temp->next = del->next;
    delete del;
}

void printList(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{
    node *head = NULL;
    // insertAtHead(head, 4);
    insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);
    printList(head);
    deleteNode(head, 3);
    printList(head);
}
