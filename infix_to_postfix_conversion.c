#include <stdio.h>          //header file declaration
#include <string.h>
#define size 20            // stack size 20
char stack[size];           //stack initialization
int top = -1;
void push(char item)        //push function to insert item in stack
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
char pop()                  //pop function to delete item from the stack
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
int precedence(char symbol)         //precedence function to check the precedence of the operator
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
    case ')':
    case '(':
    case '#':
        return 1;
        break;
    }
}
int isoperator(char symbol)             //condition for operator checking
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
    }
}
void convert(char infix[], char postfix[])          //convert function
{

    int j = 0;
    int i = 0;
    stack[top++] = '#';
    for (i = 0; i < strlen(infix); i++)
    {
        int ch = infix[i];
        if (isoperator(ch)==0)      //operand checking
        {
            postfix[j] = ch;
            j++;
        }
        else
        {
            if (ch == '(')
            {
                push(ch);
            }
            else

            {
                if (ch == ')')
                {
                    while (ch != '(')
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    pop();
                }
                else
                {

                    if (precedence(ch) > precedence(stack[top]))
                    {
                        push(ch);
                    }
                    else
                    {
                        while (precedence(ch) <= precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(ch);
                    }
                }
            }
        }
    }

    while(stack[top]!='#')          //POP ALL the item from the stack
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
}
void main()             //main function
{
    char infix[]={"a+b*c/d-f"};         //infix expression
    char postfix[25];
    printf("infix expression is %s:\n",infix);      //printing infix
    convert(infix,postfix);
    printf("postfix expression is :%s\n",postfix);      //printing postfix
}