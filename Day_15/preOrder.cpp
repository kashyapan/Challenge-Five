#include<bits/stdc++.h>

using namespace std ;

class nodeClass{

public :
    int data ;
    nodeClass *right ;
    nodeClass *left ;

    nodeClass(int data) {
        this->data = data ;
        
        right = left = NULL ;

    }
} ;


nodeClass* insert(nodeClass* root , int key) {

    if(root == NULL) {
        nodeClass* temp = new nodeClass(key) ;
        root = temp ;
        
        return temp ;
    } else if (root->data > key) {
        root->left = insert(root->left , key) ;
    } else if (root->data < key) {
        root->right = insert(root->right , key) ;
    }

}

nodeClass* del(nodeClass* root  , int key)  {   

    if(root != NULL) {
        if(root->data > key) {
            root->left = del(root->left , key) ;
        } else if (root->data < key) {
            root->right = del(root->right , key) ;
        } else {
            //Found Element 

            //If no child
            if(root->right == NULL && root->left == NULL) {
                nodeClass* temp = root ;
                delete temp ;
                root = NULL ;
                
            } else if(root->right == NULL || root->left == NULL ) {

                nodeClass* temp  ;

                if(root->left == NULL) {
                    temp = root ;
                    root = root->right ;
                    delete temp ;
                
                } else if (root->right == NULL) {
                    temp = root ;
                    root = root->left ;
                    delete temp ;
                
                }
            } else {

                nodeClass* mini = root->right;
                
                while(mini->left != NULL) {

                    mini = mini->left ;
                }

                root->data = mini->data ;
                root->right = del(root->right , mini->data) ;

            }
            return root ;
        }

    }

}

void inorder(nodeClass* root) {
    if(root != NULL) {

        inorder(root->left) ;
        cout << root->data <<" " ;
        inorder(root->right)  ;

    }

}

void preorder(nodeClass* root) {
    if(root != NULL) {
        cout << root->data <<" " ;
        preorder(root->left) ;
        preorder(root->right)  ;

    }
}

void preOrderItr (nodeClass* root ) {

    stack<nodeClass*>  stk ;
    stk.push(root) ;


    while(!stk.empty()) {
        nodeClass x = *stk.top() ;
        cout << x.data <<" " ;
        stk.pop() ;
        if(x.right != NULL)
            stk.push(x.right) ;

        if(x.left != NULL)            
            stk.push(x.left) ;        

    }

    cout << endl ;
}


int main() {

    freopen("in.txt" , "r" , stdin ) ;
    nodeClass* root = NULL ;
    int t ;
    int ele ;


    cin >> t ;
    while(t--) {
        cin >> ele ;
        root = insert(root , ele) ;
    }

    preorder(root) ;
    cout<< endl ;
    preOrderItr(root) ;
    return 0 ;
}
