#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;

/* UTILITY FUNCTIONS */
/* Function to push a node */

  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    freopen("in.txt" , "r" , stdin);
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);

     printList(head);
     }
     return(0);
}
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method

  struct node* prev = NULL ; 
  struct node* next = NULL ; 
  struct node* curr = head ; 
  struct node* st = head ; 
  struct node* eoL = NULL ;

  int count = 0 ;
  head = NULL ;


  while(curr != NULL) {
      count ++ ;
      next = curr->next ;
      curr->next = prev ;
      prev = curr ;
      curr = next ;

      //Customized part

      if( (count % k == 0) || (curr == NULL) ) {
//          cout << "Break  at "<< prev->data <<" pos "<< count <<endl ;

          if(head == NULL) {
              head = prev ;
          } else {
              eoL->next =  prev ;
          }

//          eoL->next = prev ;
          eoL = st ;
          prev = NULL ;
          st = curr ;

      }

  }

 // head = prev ;

  return head ;


  
}
