#include<stdio.h>
#include<stdlib.h>
// #include "singlylist.h"

struct node
{
      int data;
      struct node *next;
}*first=NULL,*temp,*t;

int n;
void createsl(int);
void printsl(void);
void insertsl(int);
void deletepsl(int);
void deletevsl(int);
void searchsl(int);
void reversesl(void);

main()
{
    int pos,op=1,x;

    while (op>=1 && op<=7)
    { 
          printf("\n\n Singly Linked List Operations");
          printf("\n 1.Create a Singly Linked List");
          printf("\n 2.Display a Singly Linked List");
          printf("\n 3.Insert a Node in Linked List");
          printf("\n 4.Delete a Node in Linked List by position");
          printf("\n 5.Delete a Node in Linked List by value");
          printf("\n 6.Search a Node in Linked List");
          printf("\n 7.Reverse Of Singly Linked List");
          printf("\n 8.Exit");
    
          printf("\n\n Enter an Option to perform Desired Operation : ");
          scanf("%d",&op);
    
          switch(op)
          {
                case 1 : if (first!=NULL)
                          {
                              printf("\n The Linked List is already created..\n");
                              printsl();
                          }
                          else
                          {
                              printf("\n Enter number of nodes in linked list : ");
                              scanf("%d",&n);
                              if (n<=0)
                              {
                                 printf("\n Error!!Invalid number of nodes..\n");
                                 return;   
                              }
                              createsl(n);
                           }
                           break;
 
                case 2 : if (first==NULL)
                             printf("\n Singly Linked List is Empty...\n");
                         else 
                             printsl();
                         break;
              
                case 3 : printf("\nEnter the position to insert new node : ");
                         scanf("%d",&pos);
                         if (pos<1 || pos>n+1)
                            printf("\n Error...Enter Valid Position..");
                         else
                            insertsl(pos);
                            printsl();
                         break;

                case 4 : if (first==NULL)
                            printf("\n ERROR..Singly Linked List is Empty...\n");
                         else
                         {
                            printf("\n Enter the position to delete node : ");
                            scanf("%d",&pos);
                            if (pos<1 || pos>n+1)
                                printf("\n Error...Enter Valid Position..\n");
                            else 
                                deletepsl(pos);
                                printsl();
                         }
                         break;
                        
                case 5 : if (first==NULL)
                            printf("\n ERROR..Singly Linked List is Empty...\n");   
                         else
                         {
                            printf("\n Enter value of node to be deleted : ");
                            scanf("%d",&x);
                            deletevsl(x);
                            printsl();
                         }
                         break;

               case 6 : if (first==NULL)
                            printf("\n ERROR..Singly Linked List is Empty...\n");
                        else
                        {
                            printf("\n Enter value of node to be searched : ");
                            scanf("%d",&x);
                            searchsl(x);
                        }
                        break; 

               case 7 : if (first==NULL) 
                            printf("\n NOT POSSIBLE..");
                        else
                            reversesl();
                            printsl();
                        break;  
         } 
    }
}


void createsl(n)
{
     int i;
     for (i=1;i<=n;i++)
     {
         temp=malloc(sizeof(struct node));
         printf("\n Enter Data for node %d : ",i);
         scanf("%d",&temp->data);
         
         if (i==1)
            first=t=temp;
         else
         {
            t->next=temp;
            t=temp;
         }
     }
     printsl();
}

void printsl(void)
{
     if (first==NULL)
        printf("\n SINGLY LINKED LIST IS EMPTY.");
     else
     {
        printf("\n The Singly linked list is :\n start-->");
        for (t=first;t->next!=NULL;t=t->next)
             printf(" %d ->",t->data);
        printf(" %d ->NULL",t->data);
     }
}

void insertsl(pos)
{
     int i;
     
     temp=malloc(sizeof(struct node));
     printf("\nEnter Data for Singly Linked List : ");
     scanf("%d",&temp->data);
     printf("%d",temp->data);
     if (pos==1)
     {
         temp->next=first;
         first=temp;
     }
     else
     {
         for (i=1,t=first;i<pos-1 && t->next!=NULL;t=t->next,i++);
         temp->next=t->next;
         t->next=temp;
     }
     n++;
     printf("\n After Insertion , number of nodes : %d ",n);
}

void deletepsl(pos)
{
    int i;
    if (pos==1)
    {
       temp=first;
       first=first->next;
    }
    else
    {
       for (i=1,t=first;i<pos-1 && t->next!=NULL; t=t->next,i++);
       temp=t->next;
       if (temp->next!=NULL)
           t->next=temp->next;
    }
    n--;
    printf("\n After Deletion , number of nodes : %d ",n);
}

void deletevsl(x)
{
     for (t=first;t!=NULL;t=t->next)
     {
         if (t->data==x)
            break;
         temp=t;
     }
     if (t==NULL)
         printf("\nThe value %d is not found in singly linked list..",x);
     else
         if (t==first)
             first=first->next;   
         else
            temp->next=t->next;  
}

void searchsl(x)
{
     int i=0;
     for (t=first;t!=NULL;t=t->next)
     {
         i++;
         if (t->data==x)
         {
            printf("\n The value %d is found at %d postion",x,i);
            return;
         }
     } 
     printf("\n The value %d is not found in singly linked list",x);
}

void reversesl(void)
{
     struct node *t1,*t2;
     for (t=first,t1=t->next,t2=t1->next;t1->next!=NULL;t2=t2->next)
     { 
         t1->next=t;  
         t=t1;
         t1=t2;
     }
     t1->next=t;
     first->next=NULL;
     first=t1;
     printf("\n Reversed Single Linked List is :");
}


/*OUTPUT
[sy51@pc56 Assignment no.4]$ cc ll.c
[sy51@pc56 Assignment no.4]$ ./a.out


 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 2

 Singly Linked List is Empty...


 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 1

 Enter number of nodes in linked list : 5

 Enter Data for node 1 : 11

 Enter Data for node 2 : 22

 Enter Data for node 3 : 33

 Enter Data for node 4 : 44

 Enter Data for node 5 : 55

 The Singly linked list is :
 start--> 11 -> 22 -> 33 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 3

Enter the position to insert new node : 1

Enter Data for Singly Linked List : 10
10
 After Insertion , number of nodes : 6 
 The Singly linked list is :
 start--> 10 -> 11 -> 22 -> 33 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 3

Enter the position to insert new node : 4

Enter Data for Singly Linked List : 40
40
 After Insertion , number of nodes : 7 
 The Singly linked list is :
 start--> 10 -> 11 -> 22 -> 40 -> 33 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 3

Enter the position to insert new node : 8

Enter Data for Singly Linked List : 80
80
 After Insertion , number of nodes : 8 
 The Singly linked list is :
 start--> 10 -> 11 -> 22 -> 40 -> 33 -> 44 -> 55 -> 80 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 3

Enter the position to insert new node : 0

 Error...Enter Valid Position..
 The Singly linked list is :
 start--> 10 -> 11 -> 22 -> 40 -> 33 -> 44 -> 55 -> 80 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 3

Enter the position to insert new node : 10

 Error...Enter Valid Position..
 The Singly linked list is :
 start--> 10 -> 11 -> 22 -> 40 -> 33 -> 44 -> 55 -> 80 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 7

 Reversed Single Linked List is :
 The Singly linked list is :
 start--> 80 -> 55 -> 44 -> 33 -> 40 -> 22 -> 11 -> 10 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 7

 Reversed Single Linked List is :
 The Singly linked list is :
 start--> 10 -> 11 -> 22 -> 40 -> 33 -> 44 -> 55 -> 80 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 6

 Enter value of node to be searched : 10

 The value 10 is found at 1 postion..

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 6

 Enter value of node to be searched : 40

 The value 40 is found at 4 postion..

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 6

 Enter value of node to be searched : 80

 The value 80 is found at 8 postion..

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 5

 Enter value of node to be deleted : 10

 The Singly linked list is :
 start--> 11 -> 22 -> 40 -> 33 -> 44 -> 55 -> 80 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 5

 Enter value of node to be deleted : 40

 The Singly linked list is :
 start--> 11 -> 22 -> 33 -> 44 -> 55 -> 80 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 5

 Enter value of node to be deleted : 80

 The Singly linked list is :
 start--> 11 -> 22 -> 33 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 4

 Enter the position to delete node : 11

 Error...Enter Valid Position..

 The Singly linked list is :
 start--> 11 -> 22 -> 33 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 4

 Enter the position to delete node : 1 

 After Deletion , number of nodes : 7 
 The Singly linked list is :
 start--> 22 -> 33 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 4

 Enter the position to delete node : 2

 After Deletion , number of nodes : 6 
 The Singly linked list is :
 start--> 22 -> 44 -> 55 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 4

 Enter the position to delete node : 3

 After Deletion , number of nodes : 5 
 The Singly linked list is :
 start--> 22 -> 44 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 5

 Enter value of node to be deleted : 44

 The Singly linked list is :
 start--> 22 ->NULL

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 4

 Enter the position to delete node : 1

 After Deletion , number of nodes : 4 
 SINGLY LINKED LIST IS EMPTY.

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 4

 ERROR..Singly Linked List is Empty...


 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 5

 ERROR..Singly Linked List is Empty...


 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 6

 ERROR..Singly Linked List is Empty...


 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 7

 NOT POSSIBLE..
 SINGLY LINKED LIST IS EMPTY.

 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 2

 Singly Linked List is Empty...


 Singly Linked List Operations
 1.Create a Singly Linked List
 2.Display a Singly Linked List
 3.Insert a Node in Linked List
 4.Delete a Node in Linked List by position
 5.Delete a Node in Linked List by value
 6.Search a Node in Linked List
 7.Reverse Of Singly Linked List
 8.Exit

 Enter an Option to perform Desired Operation : 8

 */


 
       




    


 
