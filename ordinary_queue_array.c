// Implementation of a queue using an array
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
void insert();  // insert function prototype
void delete();  // delete function prototype
void display(); // display function prototype
int front = -1, rear = -1;
int queue[maxsize];
void main() // main function
{
    int choice;
    while (choice != 4)
    {
        printf("Main Menu\n");
        printf("1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("Enter your choice ?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(); // function calling
            break;
        case 2:
            delete (); // function calling
            break;
        case 3:
            display(); // function calling
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid choice??\n");
        }
    }
}
void insert() // insert function declaration
{
    int item;
    printf("Enter the element\n");
    scanf("%d", &item);
    if (rear == maxsize - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("Value inserted\n");
}
void delete() // delete function declaration
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("value deleted\n");
    }
}
void display() // display function declaration
{
    int i;
    if (rear == -1)
    {
        printf("Empty queue\n");
    }
    else
    {
        printf("printing values .....\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}