#include<bits/stdc++.h>
using namespace std;

void process(string s){
    stack<int> stk ;
    int count = 1 ;
    cout << "For exp " << s <<endl ;
    for(int i = 0 ;i < s.length() ; i++) {
        
        if(s[i] == '(' || s[i] == ')' ) {
            if(s[i] == '(') {
                stk.push(count) ;
                cout << count << " " ;
                count ++ ;
            } else if(s[i] == ')') {
                cout << stk.top() <<" ";
                stk.pop() ;
            }
        }

    } 

    cout << endl ;
    while(!stk.empty())
        stk.pop() ;
}



int main(){
    string inp ;
    int t , ele ;

    freopen("in.txt" , "r" , stdin ) ;
    cin >> t ;
    
    while(t--) {

        cin >> inp ;
        process(inp) ;

    }
   

    return 0 ; 
}