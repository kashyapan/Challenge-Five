#include<bits/stdc++.h>
using namespace std;

void isort( vector<int> &vec ){

    int i, j, temp, len;

    len=vec.size();

    for(i=1;i<len;i++){
        temp = vec[i];
        for(j=i;j>0;j--){
            vec[j]=vec[j-1];
        }
        vec[j]=temp;
    }
}


void bsort( vector<int> &vec ){

    int i, j, temp, len;

    len=vec.size();

    for(i=0;i<vec.size();i++){
        for(j=i;j< vec.size() ;j++){
            if(vec[i] > vec[j])
                swap(vec[i] , vec[j]) ;
        }
    }
}

int main(){
    vector<int> vec ;
    int t , ele ;

    freopen("in.txt" , "r" , stdin ) ;
    cin >> t ;
    
    while(t--) {
        cin >>ele ;
        vec.push_back(ele) ;
    }
   
    bsort(vec) ;    

    for(int i = 0 ; i < vec.size() ; i++) {
        cout << vec[i] <<" " ;
    }    
    cout << endl ;   

    return 0 ; 
}