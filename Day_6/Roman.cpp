#include <bits/stdc++.h>

using namespace std;

int getDecimal(char c) {
    map<char , int >  hm ;
    hm.insert( pair<char , int> ('I' , 1) ) ;
    hm.insert( pair<char , int> ('V' , 5) ) ;
    hm.insert( pair<char , int> ('X' , 10) ) ;
    hm.insert( pair<char , int> ('L' , 50) ) ;
    hm.insert( pair<char , int> ('C' , 100) ) ;

    return hm.find(c)->second ;
}

int main() {

    string str = "CXC" ;

  //  cout << str.back() <<endl ;
    int  count = 0 ; 
    
    int prev = getDecimal( str.back() ) ;
    
    count += prev ;
    
    for(int i = str.length() - 2  ; i >= 0 ; i-- ) {
        int curr = getDecimal( str[i] ) ;

        if ( curr >=  prev ){
            count += curr ;
        } else {
            count -= curr ;
        }

        prev = curr ;


    }
    
    cout << count << endl  ;
	return 0;
}
