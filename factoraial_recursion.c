#include<stdio.h>       //header file declaration
int factorial(int n);   //function declaration
void main()             //main function
{
    int n;
    printf("enter the no. to get factorial of");
    scanf("%d",&n);             //inputing factorial no.
    printf("%d",factorial(n));
}
int factorial(int n)        //factorial function
{
    if(n==0)        //base condition
    {
        return 1;

    }
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);    //calculating factorial

    }
}
