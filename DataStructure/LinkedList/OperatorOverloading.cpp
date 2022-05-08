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

istream &operator>>(istream &os, node *&head)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertAtHead(head, data);
        cin >> data;
    }
    return os;
}

ostream &operator<<(ostream &os, node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return os;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    cin >> head1 >> head2;
    cout << head1 << head2;
}
