#include <stdio.h>  //header file declaration
#include <string.h> //header file declaration
#define size 20     // size define
int top1 = -1;
char stack_int[size];

void push_int(int item) // push function
{
    stack_int[++top1] = item;
}
int pop_int() // pop function to delete from the stack
{
    return stack_int[top1--];
}
int eval_prefix(char prefix[]) // evalaution
{
    int i = 0;
    int operand1, operand2;
    char ch;
    while (prefix[i] != '\0')
    {
        ch = prefix[i];
        if (ch >= '0' && ch <= '9')
        {
            push_int(ch - '0');
        }
        else
        {
            int operand1 = pop_int();

            int operand2 = pop_int();

            switch (ch)
            {
            case '+':
                push_int(operand1 + operand2);
                break;
            case '-':
                push_int(operand1 - operand2);
                break;
            case '*':
                push_int(operand1 * operand2);
                break;
            case '/':
                push_int(operand1 / operand2);
                break;
            }
        }
        i++;
    }
    return pop_int();
}
int reverse(char infix[]) // reverse function to reverse the string
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
void main() // main function
{
    char infix[] = {"+++1234"}; // infix expression
    printf("thr prefix expression is :%s\n", infix);
    reverse(infix);

    printf("the evaluation of prefix expression is :%d\n", eval_prefix(infix)); // printing evaluation
}
