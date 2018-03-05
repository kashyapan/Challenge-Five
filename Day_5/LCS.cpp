#include <bits/stdc++.h>

using namespace std;

int max (int x , int y) {
    if (x > y) return x ;

    return y ;
}
int main() {

    string str1 = "abcdaf" ;
    string str2 = "acbcf" ;

    int m , n ;

    m = str1.length() ;
    n = str2.length() ;

    int  arr[m+1][n+1] ;

    //init for zeros 

    for(int i = 0 ; i <= m ; i++) {
        for(int j = 0 ; j <= n ; j++) {
            arr[i][j] = 0 ;
        }
    }

    for(int i = 0 ; i <= m ; i++ ) {
        arr[i][0] = 0 ;
    }

    for(int i = 0 ; i <= n ; i++ ) {
        arr[0][i] = 0 ;
    }    

    for(int i = 0 ; i <= m ; i++) {
        for(int j = 0 ; j <= n ; j++) {
            cout << arr[i][j] << " " ;
        }
        cout << endl ;
    }

//real work

    for(int i = 1 ; i <= m ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            int x ;
            if( str1[i-1] == str2[j-1] ) {
                x = arr[i-1][j-1] + 1 ; 
            } else {
                x = max( arr[i-1][j] , arr[i][j-1] ) ;
            }
            arr[i][j] = x ;
        }
    }
    
    for(int i = 0 ; i <= m ; i++) {
        for(int j = 0 ; j <= n ; j++) {
            cout << arr[i][j] << " " ;
        }
        cout << endl ;
    }

	return 0;
}
