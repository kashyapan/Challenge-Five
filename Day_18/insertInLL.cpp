#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insertAtBegining(struct node** headRef, int newData);

void insertAtEnd(struct node** headRef, int newData);

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<' ';
        node = node->next;
    }
    cout<<'\n';
}

int main()
{
    freopen("in.txt" , "r" , stdin) ;
    int test;
    cin>>test;
    while(test--)
    {
        int n, ch, tmp;
        struct node* head = NULL;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp>>ch;
            if(ch) insertAtEnd(&head, tmp);
            else insertAtBegining(&head, tmp);
        }
        printList(head);
    }
    return 0;
}

// function inserts the data in front of the list
void insertAtBegining(struct node** headRef, int newData)
{
    // Code here

    struct node* newNode = new struct node ;
    newNode->data = newData ;
    newNode->next = (*(headRef)) ;
    *headRef = newNode ;
 
}
// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    // Code here

    struct node* temp = *headRef ;

    if(temp == NULL) {
        //It is First Node 
        insertAtBegining(headRef , newData) ;
        return ;
    }

    struct node* newNode = new struct node ;
    newNode->data = newData ;
    newNode->next = NULL ;



    while(temp->next  != NULL) {
        temp  = temp->next ;
    }

    temp->next = newNode ;
}