#include<bits/stdc++.h>
using namespace std ;

int main() {
	
	int t , n ;

    
    stack<string> stk ;
    string s ;

	cin >> t ;
	
	while(t--) {

        cin >> n ;

        for(int i = 0 ; i < n ; i++) {
            cin >> s ;

            if(!stk.empty()) {
                if(stk.top() == s) {
                     stk.pop() ;
                     continue ;
                } 
            }

            stk.push(s) ;
        }

        cout << stk.size() <<endl ;

        while( !stk.empty() ) {
            stk.pop() ;
        }

    }

	return 0 ;

}