#include <bits/stdc++.h>

using namespace std;

/*
--CORRECT-- checked by submitting to GFG
Normal insertion in BST + balancing

-Height of leaf node is 1
-Height of NULL is 0
-Rotation types
    -LL
    -LR
    -RR
    -RL
-While rotating fix root height first <IMPORTANT> then newNode Height
-Use preorder / postorder to verify

*/

class node {
    public :
        int data , height ;
        node *right ;
        node *left ;

    node(int data) {
        this->data = data ;
        this->height = 1 ;
        right = NULL ;
        left = NULL ;
    }
} ;

int max (int x , int y) {

    if(x > y ) return x ;

    return y ;
}

int heightOfTree(node* root) {

    if(root == NULL) return 0 ;

    return root->height ;
} 

node* leftRotate(node* root ) {

    node* newNode  = root->right ;
    root->right = newNode->left ; 
    newNode->left = root ;
    root->height = 1 + max(heightOfTree (root->left) , heightOfTree(root->right)) ;
    newNode->height = 1 + max(heightOfTree (newNode->left) , heightOfTree(newNode->right))  ;
    return newNode ;
}

node* rightRotate(node* root) {
    node* newNode = root->left ;
    root->left = newNode->right ;
    newNode->right = root ;
    root->height = 1 + max(heightOfTree (root->left) , heightOfTree(root->right)) ;
    newNode->height = 1 + max(heightOfTree (newNode->left) , heightOfTree(newNode->right))  ;    
    return newNode ;
}

node* ins(node* root , int key) {

	if(root == NULL) {
		//we need a new
        root = new node(key) ; 
     //   return root ;
	} else if (key < root->data ) {
        //Move left
        root->left = ins(root->left , key) ;

    } else if (key > root->data) {
        //move right
        root->right = ins(root->right , key) ;
    } else {
        return root ;
    }

    //left - right
    int balance = heightOfTree(root->left) - heightOfTree(root->right ) ;

    cout << root->data <<" --> " << heightOfTree(root->left) <<" - "<< heightOfTree(root->right) <<"  = " << balance <<endl ;
    if(balance > 1) {
        //left is more needs right rotaion
        if( heightOfTree(root->left->left) >= heightOfTree(root->left->right) ) {
            return rightRotate(root) ;
        } else {
            root->left = leftRotate(root->left) ;
            return rightRotate(root) ;
        }


    }

    if(balance < -1) {
        if( heightOfTree(root->right->right) >= heightOfTree(root->right->left) ) {
            return leftRotate(root) ;
        } else {
            root->right = rightRotate(root->right) ;
            return leftRotate(root) ;
        }
    }

    root->height = 1+ max(heightOfTree (root->left) , heightOfTree(root->right)) ;
    cout << "Updating height " <<root->data << " -> " << root->height <<endl ; 
    return root ;

} 

void inOrder (node* root ) {

    if(root != NULL) {
        inOrder(root->left) ;
        cout << root->data <<" "<< root->height<< endl  ;
        inOrder(root->right) ;
    }
}

void preOrder (node* root ) {

    if(root != NULL) {
        cout << root->data <<" "<< root->height<< endl  ;
        preOrder(root->left) ;
        preOrder(root->right) ;
    }
}                                   



int main() {

	node* root = NULL ;
/*
    root = ins(root ,45 ) ;
    root = ins(root ,50 ) ;
    root = ins(root ,47 ) ;    
    root = ins(root ,60 ) ;
*/
    root = ins(root , 1 ) ;
    root = ins(root , 2 ) ;
    root = ins(root , 3 ) ;
 /*   root = ins(root , 7 ) ;
    root = ins(root , 6 ) ;
    root = ins(root , 5 ) ;
    root = ins(root , 4 ) ;
    root = ins(root , 2 ) ;
    root = ins(root , 2 ) ;
*/


	preOrder(root) ;
    

	return 0;
}