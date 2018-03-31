#include<bits/stdc++.h>

using namespace std;

struct Node
{
int data;
Node* next;
};

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


Node *compute(Node *head);

int main()
{
    freopen("in.txt" , "r" , stdin);
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}

        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};

4
8
12 15 10 11 5 6 2 3
6
10 20 30 40 50 60
6
60 50 40 30 20 10
93
32 433 636 121 831 102 695 509 104 776 905 876 219 202 326 393 141 752 504 109 640 765 537 759 971 857 147 716 897 484 60 928 268 47 48 98 500 94 607 603 221 863 831 439 416 156 183 556 259 686 16 250 450 552 9 772 409 155 487 305 990 898 232 258 945 631 707 444 724 313 47 296 527 229 734 942 736 268 849 995 953 865 244 754 416 604 526 176 110 364 832 100 262
*/
bool isThereABigOne ;

Node* computeR(Node *head)
{
// your code goes here
  Node* prev = NULL ; 
  Node* next = NULL ; 
  Node* temp = NULL ; 
  Node* curr = head ; 
  isThereABigOne = false ;

  while( curr != NULL) {

      next = curr->next ;
      
      if(next == NULL) break ;

      if(next->data > curr->data) {
          isThereABigOne = true ;
          temp = curr ;
          
          if(prev == NULL) {
            head = next ;
          } else {
            prev->next = next ;
          }

          curr = next ; 
     //     delete temp ;
          continue ;    
      }

    /*
    if(prev != NULL) {
        if(prev->data < curr->data) {
            cout << "Violation "<<endl ;
           // prev = compute(prev) ;
           curr = prev ;
           continue ;
        }

    }*/
    
      prev = curr ;
      curr = curr->next ;
  }
  

  return  head ;

}

Node *compute(Node *head)
{
// your code goes here
do{
      head = computeR(head) ;

  }while(isThereABigOne) ;

  return head ;

}