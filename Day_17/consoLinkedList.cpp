#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
};

Node* newNode(char key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = data;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    freopen("in.txt" , "r" , stdin) ;
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
bool isVowel( char c ) {
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) {
        return true ;
    }

    return false ; 
}
struct Node* arrange(Node *head)
{
   //Code here

   Node *curr = head ;
   Node *prev = NULL ;   
   Node *temp = NULL ;      
   Node *nextItem = NULL ;

   while(curr != NULL) {

       if(isVowel(curr->data )) {
           //Do magic
           if(prev == NULL) {
               //1st Node so do nothing
               nextItem = curr ;

           } else if ( nextItem == NULL ) {
               // first  Vowel 
               prev->next = curr->next ;
               curr->next = head ;
               head = curr ;
               nextItem = curr ;
               curr = prev ;
           } else {
               prev->next = curr->next ;
               curr->next = nextItem->next ;
               nextItem->next = curr ;
               nextItem = curr ;
               curr = prev ;
           }
       }
        //Move pointer
        prev = curr ;
        curr = curr->next ;

   }

   return head ;

}