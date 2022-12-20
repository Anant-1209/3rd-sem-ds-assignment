#include <stdio.h>  //header file declaration
#include <string.h> //header file declaration
#include <stdlib.h>
#define size 20 // stack size
int top = -1;
char stack[size];    // initializing stack
void push(char item) // push function insert item into stack
{
    if (top == size - 1)
    {
        printf("overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
char pop() // pop function to delete item from the stack
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        return stack[top--];
    }
}
int precedence(char symbol) // precedence checking of operator
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '^':
        return 4;
        break;
    case '(':
    case ')':
    case '#':
        return 1;
    }
}
int isoperator(char symbol) // checking for operand
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
void convert(char infix[], char postfix[]) // function to convert from infix to prefix
{
    int i = 0;
    int j = 0;

    stack[top++] = '#';
    for (i = 0; i < strlen(infix); i++)
    {

        int item = infix[i];
        if (isoperator(item) == 0)
        {
            postfix[j] = item;
            j++;
        }
        else
        {

            if (item == ')')
            {
                push(item);
            }
            else
            {
                if (item == '(')
                {
                    while (stack[top] != ')')
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    pop();
                }
                else
                {
                    if (precedence(item) >= precedence(stack[top]))
                    {
                        push(item);
                    }
                    else
                    {
                        while (precedence(item) < precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(item);
                    }
                }
            }
        }
    }
    while (stack[top] != '#') // loop to pop all the item from stack
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

void reverse(char infix[]) // reverse function to reverse the string
{
    int i = 0;
    int j = strlen(infix) - 1;
    while (i <= j)
    {
        char temp = infix[i];
        infix[i] = infix[j];
        infix[j] = temp;
        i++;
        j--;
    }
}
void main() /// main function
{
    char infix[] = {"1+2+3"}; // infix expression
    char postfix[25];
    printf("the infix expression is :%s\n", infix);
    reverse(infix);
    // printf("the  reverse infix expression is :%s\n",infix);
    convert(infix, postfix);
    // printf(" the postfix expression is :%s\n",postfix);
    // printf(" the evaluation of prefix expression is : %d\n",eval_prefix(postfix));

    reverse(postfix);
    printf(" the prefix expression is :%s\n", postfix);
}
