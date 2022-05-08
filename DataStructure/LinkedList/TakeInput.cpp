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

node *takeInput()
{
    node *head = NULL;
    node *current = NULL;
    int n, data;
    cin >> n;
    if (n > 0)
    {
        cin >> data;
        head = new node(data);
        current = head;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> data;
        current->next = new node(data);
        current = current->next;
    }
    return head;
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
    node *head = takeInput();
    printList(head);
}
