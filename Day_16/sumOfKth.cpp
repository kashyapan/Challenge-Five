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

int countPairs(Node* root1, int x);

void preOrderItr (Node* root ) {

    stack<Node*>  stk ;
    stk.push(root) ;


    while(!stk.empty()) {
        Node x = *stk.top() ;
       
        stk.pop() ;
        if(x.right != NULL)
            stk.push(x.right) ;
        cout << x.data <<" " ;
        if(x.left != NULL)            
            stk.push(x.left) ;        

    }

    cout << endl ;
}

// Driver code
int main()
{
    freopen("in.txt" , "r" , stdin) ;
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
//        int s;
//        cin>>s;

        preOrderItr(root1) ;
     //   cout<<countPairs(root1, s)<<"\n";
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


int countPairs(Node* root,  int x)
{
    // Code here
    int count = 0 ;


    return count ;

} 