//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int kthAncestor(Node *root, int k, int node);

int main()
{
    freopen("in.txt" , "r" , stdin) ;
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int k, node;
     cin>>k>>node;
     cout<<kthAncestor(root, k, node)<<"\n";
  }
  return 0;
}

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/

void fillArray(Node* root , vector<int> &vec) {
    if(root != NULL) {
        fillArray(root->left , vec) ;
        fillArray(root->right , vec) ;
        
    }


}
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int> vec ;
    
    int count = 0 ;

    while(!stk.empty()) {
        
        if(k == count)
            return stk.top() ;

        stk.pop() ;
        count++ ;
    }

    return -1 ;
}

/*
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    stack<int> stk ;
    Node* temp = root ;
    
    while (root != NULL) {
        stk.push(root->data) ;        
        if(node > root->data ) {
            root = root->right ;
        } else if(node < root->data ) {
            root = root->left ;
        } else {
            break ;
        }

    }

    int count = 0 ;

    while(!stk.empty()) {
        
        if(k == count)
            return stk.top() ;

        stk.pop() ;
        count++ ;
    }

    return -1 ;
}
*/