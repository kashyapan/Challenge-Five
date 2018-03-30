// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

  freopen("in.txt" , "r" , stdin) ;
  // TO BE REMOVED
  for (int i=0; i<2000; i++);


    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head = deleteNode(head,kk);
    printList(head);
    }
    return 0;
}

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/
/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here

    Node* prev = NULL ;
    Node* curr = head ;
    int count = 0 ;

    while (curr != NULL) {
        count ++ ;

        if(count == x) {
            //Key found now delete it

            if(prev == NULL) {
                //First Node so adjust head also
                prev = curr->next ;
                head = prev ;
                delete curr ;
                break ;
            }

            //It is other than first node no need to adjust head

            prev->next = curr->next ;
            delete curr ;
            break ;

        }

        prev = curr ;
        curr = curr->next ;
    }

    return head ;
}
