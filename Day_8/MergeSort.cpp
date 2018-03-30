#include <bits/stdc++.h>

using namespace std;


int max (int x , int y) {

    if(x > y ) return x ;

    return y ;
}

void merge( vector<int> &vec ) {

    vector<int> vec1 ;
    vector<int> vec2 ;
    
    int s = 0 ;
    int e = vec.size() - 1;
    int m ;

    if(e % 2 == 1)
     m = ( e - s ) / 2 ;
    else 
     m = ((e - s) / 2) - 1 ;

    cout << vec[m] <<endl ;


    for(int i = 0 ; i <=m ; i++) {
        vec1.push_back( vec[i] );
    }

    for(int i = m+1 ; i <=e ; i++) {
        vec2.push_back( vec[i] );
    }    

    cout << "Vec 1" <<endl ;
    for(int i = 0 ; i < vec1.size() ; i++) {
        cout << vec1[i] <<" " ;
    }    
    cout << endl ;
    cout << "Vec 2" <<endl ;
    for(int i = 0 ; i < vec2.size() ; i++) {
        cout << vec2[i] <<" " ;
    }    
    cout << endl ;    

    vec.clear() ;

    int i , j , temp ;
    i = j = 0 ;

    while ( i < vec1.size() && j < vec2.size()  ) {
        if( vec1[i] < vec2[j] ) {
            temp = vec1[i++] ;
        } else {
            temp = vec2[j++] ;
        }

        vec.push_back(temp) ;
    }

    while(i < vec1.size() ) {
        vec.push_back(vec1[i++]) ;
    }

    while(j < vec2.size() ) {
        vec.push_back(vec2[j++]) ;
    }    


}

int main() {

    vector<int> vec , vec1 , vec2 ;
    int t , ele ;

    vec.push_back(1) ;
    vec.push_back(3) ;
//    vec.push_back(7) ;
//    vec.push_back(10) ;            

    vec.push_back(-2) ;
    vec.push_back(5) ;
    vec.push_back(6) ;
//    vec.push_back(8) ;
//    vec.push_back(12) ;                
   
    merge( vec) ;

    cout << "Final Merge"<<endl ;

    for(int i = 0 ; i < vec.size() ; i++) {
        cout << vec[i] <<" " ;
    }    
    cout << endl ;

	return 0;
}