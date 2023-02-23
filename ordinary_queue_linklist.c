// Implementation of Queues using Linked list
#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
 int data; 
 struct node *next; 
}; 
struct node *front; 
struct node *rear; 
void insert(); //insert function prototype
void delete(); //delete function prototype
void display(); //display function prototype
void main () //main function
{ 
 int choice; 
 while(choice != 4) 
 { 
 printf("Menu\n"); 
 printf("1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n"); 
 printf("Enter your choice ?\n"); 
 scanf("%d",&choice); 
 switch(choice) 
 { 
 case 1: insert(); 
 break; 
 case 2: delete(); 
 break; 
 case 3: display(); 
 break; 
 case 4: exit(0); 
 break; 
 default: printf("\nEnter valid choice??\n"); 
 } 
 } 
} 
void insert() //insert function declaration
{ 
 struct node *ptr; 
 int item; 
 
 ptr = (struct node *) malloc (sizeof(struct node)); 
 if(ptr == NULL) 
 { 
 printf("OVERFLOW\n"); 
 return; 
 } 
 else 
 { 
 printf("Enter value?\n"); 
 scanf("%d",&item); 
 ptr -> data = item; 
 if(front == NULL) 
 { 
 front = ptr; 
 rear = ptr; 
 front -> next = NULL; 
 rear -> next = NULL; 
 } 
 else 
 { 
 rear -> next = ptr; 
 rear = ptr; 
 rear->next = NULL; 
 } 
 } 
} 
void delete () //delete function declaration
{ 
 struct node *ptr; 
 if(front == NULL) 
 { 
 printf("UNDERFLOW\n"); 
 return; 
 } 
 else 
 { 
 ptr = front; 
 front = front -> next; 
 free(ptr); 
 } 
} 
void display() //display function declaration
{ 
 struct node *ptr; 
 ptr = front; 
 if(front == NULL) 
 { 
 printf("Empty queue\n"); 
 } 
 else 
 { printf("printing values\n"); 
 while(ptr != NULL) 
 { 
 printf("%d\n",ptr -> data); 
 ptr = ptr -> next; 
 } 
 } 
} 