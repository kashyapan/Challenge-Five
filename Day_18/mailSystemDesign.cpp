#include<bits/stdc++.h>
using namespace std ;

int main() {
	
    freopen("in.txt" , "r" , stdin) ;

	int t , n, q , cmd , id ;

    list<int> unread ;
    list<int> read ;
    list<int> trash ;
    list<int> ::iterator it ;

	cin >> t ;
	
	while(t--) {

        cin >> n >> q ;

        for(int i = 1 ; i <= n ; i++) {
            unread.push_back(i) ;
        }

        //Got a list with unread mails

        for(int i = 0 ; i < (q) ; i++) {
            cin >> cmd >> id ;
            //cout << "Query " << cmd <<" "<< id <<endl  ;
            switch(cmd) {
                case 1:{
                    //1 X : Move the message with ID X from UNREAD to READ.
                    unread.remove(id) ;
                    read.push_back(id) ;
                    break ;
                }
                case 2:{
                    //2 X : Move the message with ID X from READ to TRASH.
                    read.remove(id) ;
                    trash.push_back(id);
                    break ;
                }
                case 3:{
                    //3 X : Move the message with ID X from UNREAD to TRASH.
                    unread.remove(id) ;
                    trash.push_back(id);
                    break ;
                }
                case 4:{
                    //4 X : Move the message with ID X from TRASH to READ.
                    trash.remove(id); 
                    read.push_back(id);
                    break ;
                }

            }


        }

        //Display all lists

        for(it = unread.begin() ; it != unread.end() ; ++it){
            cout << *it <<" " ;
        }
        if(unread.begin() == unread.end()) {
            cout <<"EMPTY" ;
        }
        cout << endl ;

        for(it = read.begin() ; it != read.end() ; ++it){
            cout << *it <<" " ;
        }
        if(read.begin() == read.end()) {
            cout <<"EMPTY" ;
        }
        cout << endl ;

        for(it = trash.begin() ; it != trash.end() ; ++it){
            cout << *it <<" " ;
        }
        if(trash.begin() == trash.end()) {
            cout <<"EMPTY" ;
        }
        cout << endl ;        

        //clear all lists
        read.clear ();
        unread.clear() ;
        trash.clear() ;

    }

	return 0 ;

}