// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node {
	int data;
	Node* left, *right;
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    freopen("in.txt" , "r" , stdin) ;
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
//Answers for test cases 3 2 

bool srch(Node* root , int key) {
    Node* temp = root ;

    while(temp != NULL) {
        if(key > temp->data ){
            temp = temp->right ;
        } else if( key < temp->data ) {
            temp = temp->left ;
        } else {
            return true;
        }
    }

    return false ;
}


int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    int count = 0 ;

    if(root1 != NULL) {
        int diff = (x  - root1->data  ) ;
     //   cout << "Root "<< root1->data <<" Searching " << diff <<endl; 
        if(srch(root2 , diff)) {
      //  cout << "Found "<<diff <<endl ;
//            cout << "Sum " << x<<" Root1 " << root1->data <<" " << diff <<endl; 
            count ++ ;
        }
        count += countPairs(root1->left, root2, x) ;
        count += countPairs(root1->right, root2, x ) ;
    }

    return count ;

}