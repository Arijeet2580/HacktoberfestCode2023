#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself to create a circular link
        newNode->prev = newNode;
        return newNode;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return head;
}

struct Node *insertAfter(struct Node *head, int afterData, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is empty, cannot insert after.\n");
        return head;
    }
    struct Node *current = head;
    do
    {
        if (current->data == afterData)
        {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            return head;
        }
        current = current->next;
    } while (current != head);
    printf("Node with data %d not found.\n", afterData);
    return head;
}

struct Node *deleteNode(struct Node *head, int data)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return head;
    }
    struct Node *current = head;
    do
    {
        if (current->data == data)
        {
            if (current == head)
            {
                head = head->next;
                head->prev = current->prev;
                current->prev->next = head;
                free(current);
                return head;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return head;
        }
        current = current->next;
    } while (current != head);

    printf("Node with data %d not found.\n", data);
    return head;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Head)\n");
}

int main()
{
    struct Node *head = NULL;

    while (1)
    {
        printf("\nDoubly Circular Linked List Menu\n");
        printf("1. Create a new list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert after a node\n");
        printf("5. Delete a node\n");
        printf("6. Display the linked list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        int choice, data, afterData;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = NULL;
            printf("New list created.\n");
            break;
        case 2:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 3:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter data of the node after which to insert: ");
            scanf("%d", &afterData);
            head = insertAfter(head, afterData, data);
            break;
        case 5:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            head = deleteNode(head, data);
            break;
        case 6:
            printf("Linked List: ");
            display(head);
            break;
        case 7:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
