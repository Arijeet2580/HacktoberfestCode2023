#include <stdio.h>
#include <stdlib.h>
// 22BIT0210

struct PriorityQueue
{
    int elements[5];
    int rear;
};

struct PriorityQueue pq;

void enqueue(int value)
{
    if (pq.rear == 5 - 1)
    {
        printf("Priority Queue is full\n");
        return;
    }

    int i = pq.rear;
    while (i >= 0 && pq.elements[i] < value)
    {
        pq.elements[i + 1] = pq.elements[i];
        i--;
    }

    pq.elements[i + 1] = value;
    pq.rear++;
}

void dequeue()
{
    if (pq.rear == -1)
    {
        printf("Priority Queue is empty\n");
    }
    else
    {
        printf("Deleted: %d\n", pq.elements[0]);

        for (int i = 0; i < pq.rear; i++)
        {
            pq.elements[i] = pq.elements[i + 1];
        }

        pq.rear--;
    }
}

void display()
{
    if (pq.rear == -1)
    {
        printf("Priority Queue is empty\n");
    }
    else
    {
        printf("Priority Queue elements:\n");
        for (int i = 0; i <= pq.rear; i++)
        {
            printf("Value: %d\n", pq.elements[i]);
        }
    }
}

int main()
{
    pq.rear = -1;

    int choice, value;

    do
    {
        printf("\nPriority Queue Operations:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
