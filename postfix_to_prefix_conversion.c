#include <stdio.h>//header file declaration
#include <stdlib.h>//header file declaration
#include <string.h>//header file declaration
#define size 20
int stack[size];//stack size

int top = -1;
char item;
void push(char item) //push function to insert the item in stack
{
   
    stack[++top] = item;
}
char pop()//pop function to delete the item from the stack
{
    return stack[top--];
}
int isoperand(char item)//is operand function to check for operand
{
    return (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z');
}
int isoperator(char item)//is operator to check for operator
{
    switch (item)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    }
    return 0;
}

void postfixtoprefix(char prefix[], char postfix[])//postfix to prefix cpnversion
{
    int j = 0;
    for (int i = 0; i < size; i++)//for loop
    {
        stack[i] = '\0';
    }
    printf("prefix expression is:\t");
    for (int i = strlen(postfix) - 1; i >= 0; i--)
    {
        char ch = postfix[i];
        if (isoperator(ch))//if condition checking
        {
            push(ch);
        }
        else
        {

            prefix[j++] = postfix[i];
            while ((top != -1) && (stack[top] == '#'))//while to pop operand
            {
                char operand = pop();
                prefix[j++] = pop();
            }

            push('#');
        }
    }
    prefix[j] = '\0';
    int i = 0;
    j = strlen(prefix) - 1;
    char prefix2[size];
    while (prefix[i] != '\0')//2nd while to convert prefix expression
    {
        prefix2[j--] = prefix[i++];
    }
    printf("%s\n", prefix2);
}
int main()//main function to call the conversion function
{
    char postfix[] = {"a+bc+d+"};
    char prefix[size];
    postfixtoprefix(prefix, postfix);
    return 0;
}