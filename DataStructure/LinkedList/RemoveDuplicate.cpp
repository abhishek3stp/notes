#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node* insertAtFirst(node *head, int newData)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("%4d", head->data);
        head = head->next;
    }
    printf("\n");
}

node *sort(node *head)
{
    struct node* current = head;
    while( current->next != NULL )
    {
        if( current->data == current->next->data )
        {
            struct node* hold = current->next;
            current->next = current->next->next;
            free(hold);
        }
        else
            current = current->next;
    }
    return head;
}

node *unsort(node *head)
{
    node *current = head, *trv;
    while(current != NULL && current->next != NULL)
    {
        trv = current;
        while(trv->next != NULL)
        {
            if(trv->next->data == current->data)
            {
                node* temp = trv->next;
                trv->next = trv->next->next;
                free(temp);
            }
            else
                trv = trv->next;
        }
        current = current->next;
    }
    return head;
}

int main()
{
    node *head = NULL;
    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 2);
    head = insertAtFirst(head, 2);
    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 3);
    head = insertAtFirst(head, 5);
    printf("Created Linked list is: ");
    printList(head);
    head = sort(head);
    printf("Created Linked list is: ");
    printList(head);
    head = unsort(head);
    printf("Created Linked list is: ");
    printList(head);
}