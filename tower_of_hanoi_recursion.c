#include <stdio.h>                                                 //header file declaration
void towerofhanoi(int n, char from_rod, char to_rod, char aux_rod) // tower function declaration
{
    if (n == 1) // base condition
    {
        printf("move disc 1 from rod %c to rod %c ", from_rod, to_rod);
        return;
    }

    towerofhanoi(n - 1, from_rod, aux_rod, to_rod); // recursion function
    printf("\n3move disc %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerofhanoi(n - 1, aux_rod, to_rod, from_rod);
    return;
}
int main() // main function
{
    char A, B, C;
    int n;
    printf("enter the value of n");     //print input statement
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'C', 'B');     //function calling statement
    return 0;
}
