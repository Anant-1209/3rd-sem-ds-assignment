#include <stdio.h>      //header file declaration 
#include <string.h>
#define N 20            //define size
int stack[N];           //stack initialisation
int top = -1;
void push(int data)     //push function to insert item into the stack
{
    stack[++top] = data;
}
int pop()               //pop function to pop item from the stack
{
    // int ans =
    return stack[top--];
}
int postfix_eval(char arr[])            //postfix evaluation
{
    int i = 0;
    while (arr[i] != '\0')          //while loop
    {
        char c = arr[i];
        if (c >= '0' && c <= '9')
        {
            push(c - '0');
        }
        else                    //else condition to evaluaton operations
        {
            int operand2 = pop();
            // printf("%d\n", operand2);
            int operand1 = pop();
            switch (c)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            }
        }
        i++;
    }
    return pop();
}
void main()         //main function
{
    char arr[] ="321++";
    printf("postfix expresion is: %s\n",arr);
    printf(" the evaluation of postfix is: %d", postfix_eval(arr));
}