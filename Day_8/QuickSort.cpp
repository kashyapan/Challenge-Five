#include <bits/stdc++.h>

using namespace std;


int max (int x , int y) {

    if(x > y ) return x ;

    return y ;
}

int part(vector<int> &vec , int start  , int end ) {

    int pI = start ;
    int piviot = vec[end] ;

//    cout <<start <<" "<< piviot <<" "<<end << endl ;
    for(int i = start ; i <= end ; i++) {
        if( vec[i] < piviot ) {
            swap(vec[i] , vec[pI]) ;
            pI++ ;
        }
    }      
    swap(vec[end] , vec[pI]) ;
    return pI ;

}


void QS (vector<int> &vec , int start , int end)  {

    if(end > start) {
        int div = part(vec , start , end ) ;
        //cout << div << " " <<endl ;
        QS(vec , start , div-1) ;
        QS(vec , div+1 , end) ;
    }

}


int main() {

    vector<int> vec ;
    int t , ele ;

    freopen("in.txt" , "r" , stdin ) ;
    cin >> t ;
    
    while(t--) {
        cin >>ele ;
        vec.push_back(ele) ;
    }
   

/*
    for(int i = 0 ; i < vec.size() ; i++) {
        cout << vec[i] <<" " ;
    }    
    cout << endl ;*/

  //  int x = part(vec , 0 , vec.size() -1 ) ;

//    cout << "piv pos "<< x<<endl ; 
  
    QS(vec , 0 , vec.size() -1) ;

    for(int i = 0 ; i < vec.size() ; i++) {
        cout << vec[i] <<" " ;
    }    
    cout << endl ;

	return 0;
}