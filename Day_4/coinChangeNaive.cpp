#include <bits/stdc++.h>
#define bigGuy 100000000 
#define modGuy 1000000007
using namespace std;
int calls = 0 ;

int coinChange(int total , vector<int> & coin){
    calls++ ;

    if(total <= 0) return 0 ;

    int min = bigGuy ;

    for(int i = 0 ; i < coin.size() ; i++) {
        int newTotal = total - coin[i] ;
        int temp ;

        if(newTotal < 0 ) continue ;
        
        temp = 1 + coinChange(newTotal , coin) ;

        if(min > temp) min = temp ;

    }

    return min ;

}

int main() {

    vector<int> coin ;
    int total = 13 ;

    coin.push_back(1) ;
    coin.push_back(2) ;
    coin.push_back(10) ;


    cout << coinChange(total , coin ) <<endl  ;

    cout << "called "<<calls << " times "<<endl ;

	return 0;
}