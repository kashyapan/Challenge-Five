#include<bits/stdc++.h>

using namespace std ;



int main() {

    freopen("in.txt" , "r" , stdin ) ;
    
    int t , n;
    int ele ;


    cin >> t ;
    while(t--) {
        cin >>n;
        vector<int> vec[n];

        for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> ele ;
                vec[i].push_back(ele) ;
            }
        }

        int curr_m ,curr_n ;
        int tem_m , tem_n ;
        curr_m = curr_n = tem_m = tem_n = 0 ;

        while( n > curr_m && n > curr_n) {
            tem_m = curr_m ;
            tem_n = curr_n ;

            while(tem_m < n && tem_n < n && tem_m >= 0 && tem_n >= 0) {
                cout << vec[tem_m][tem_n] <<" " ;
         //   cout << endl ;
        //    cout <<"tem_n "<< tem_n<<" --" <<endl ;
         //   cout <<"tem_m "<< tem_m<<" --" <<endl ;
                tem_m++ ;
                tem_n-- ;
            }
         //   cout << endl ;
            if((n - 1)> curr_n ) {
                curr_n++;
            } else {
                curr_m++ ;
            }
         //   cout <<"curr_n "<< curr_n<<" --" <<endl ;
          //  cout <<"curr_m "<< curr_m<<" --" <<endl ;

        }

        cout << endl ;
        /*for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < n ; j++) {
                cout << vec[i][j] << " " ;
            }
            cout << endl ;
        }   */     
    
    }

    return 0 ;
}
