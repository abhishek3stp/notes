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

bool detectCycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

void removeCycle(node *head)
{
    node *slow = head;
    node *fast = head;
    bool flag = false;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        slow = head;
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        fast->next = NULL;
    }
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
    head->next->next->next->next->next = head;
    cout << detectCycle(head) << endl;
    removeCycle(head);
    printList(head);
}
