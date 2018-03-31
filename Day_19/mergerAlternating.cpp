#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node ** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<'\n';
}

void mergeList(struct Node **head1, struct Node **head2);

// Driver program to test above functions
int main()
{
    freopen("in.txt" , "r" , stdin);    
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin>>n1;
        while(n1--){
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>n2;
        while(n2--){
            cin>>tmp;
            push(&b, tmp);
        }
        mergeList(&a, &b);
        printList(a);
        printList(b);
    }
	return 0;
}
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;
};
*/
// complete this function
void mergeList(struct Node **p, struct Node **q)
{
     // Code here
     struct Node* curr1 = *p ;
     struct Node* curr2 = *q ;
     struct Node* temp1 = NULL ;
     struct Node* temp2 = NULL ;
     
     int turn = 1 ;

     while (curr1 != NULL && (*q) != NULL) {
         
         if(!turn){
             curr1 = curr1->next ;
         } else {
             temp1 = curr1 ;
             temp2 = curr2 ;
             curr2 = curr2->next ;
             
             *q = temp2->next ;
             temp2->next = temp1->next ;
             temp1->next = temp2 ;

             
             curr1 = curr1->next ;
         }
         (turn == 1) ? (turn = 0 ) : (turn = 1) ;
     }
}