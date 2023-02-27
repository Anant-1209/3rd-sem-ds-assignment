
//Implementation of stack using Linked list.

#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
    int val;
    struct node * next;
};
struct node *head;
void push()                                   //push declaration
{
    int val;
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Not able to push the element\n");
    }
    else
    {
        printf("Enter the value\n");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->val=val;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->val=val;
            ptr->next=head;
            head=ptr;
        }
        printf("Item pushed\n");
    }
}
void pop()                                 //pop declaration
{
    int item;
    struct node * ptr;
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item=head->val;
        ptr=head;
        head=head->next;
        free(ptr);
        printf("Item popped=%d\n",item);
    }
}
void display()                                        //display declaration
{
    int i;
    struct node * ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("printing stack element\n");
        while(ptr!=NULL)
        {
            printf("%d",ptr->val);
            printf("\n");
            ptr=ptr->next;
        }
    }
}
int main()                                       //main function
{
    int choice;
    while(1)
    {
        printf("select the operation\n");
        printf("1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
            default:printf("Invalid\n");        
        }
    }
}
