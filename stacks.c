

#include<stdio.h>
#include<conio.h>
#define SIZE 20
char push();
char pop();
char peek();
 void display();
 int top=-1;
 int stack[SIZE];

void main()
{
    int ch;
    while(1)
    {

    printf("press 1 for push\n2 for pop \n 3 for peek \n 4for display \n 5 for exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        push();
        break;
         case 2:
         pop();
         break;
         case 3:
         peek();
         break;
         case 4:
         display();
         break;
         case 5:
         exit(0);
         break;
         default:printf("wrong selectio");

    }
    }

}
char push()
{
    int n;
    printf("enter the item\n");
    scanf("%d",&n);
    if(top==SIZE-1)
    {
        printf("the stack is already full");
    }
    else
    {
        top++;
        stack[top]=n;
        printf("insertion succes");
    }

}

char pop()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("item deleted from stack\n %d",stack[top]);
        top--;

    }

}
char peek()
{
    if(top==-1)
    {
        printf("stack is empty");

    }
    else
    {
        printf("the top item of stack is\n %d\n",stack[top]);
    }
}
void display()
{
    printf("\nthe elements are\n");
    for(int i=top;i>=0;i--)
    {
        printf("\n%d\n",stack[i]);
    }
}