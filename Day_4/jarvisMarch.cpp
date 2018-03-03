#include <bits/stdc++.h>
#define bigGuy 100000000 
#define modGuy 1000000007

using namespace std;

class point{
    public:
    int x , y ;

    point() {
        this->x = 0 ;
        this->y = 0 ;
    }

    point(int x , int y) {
        this->x = x ;
        this->y = y ;        
    }


    bool operator == (point const &obj) {
         return obj.x == this->x && obj.y == this->y ;
    }
};

//a , b is edge and c is target point
// returns 1 if left -1 if right 0 if co-linear

int isLeft(point a , point b , point c) {

    int x1 = a.x - b.x ;
    int x2 = a.x - c.x ;
    int y1 = a.y - b.y ;
    int y2 = a.y - c.y ;
    int res = (y2*x1 - y1*x2)  ;

    if ( res > 0 ) return 1 ;
    else if (res < 0) return -1 ;

    return 0 ; 

}

point getLeftMostEdge(vector<point> points) {

    //get least in x ;
    point min = points[0] ;

    for(int i = 0 ; i < points.size() ; i++ ) {
        if( min.x > points[i].x )
            min = points[i] ;
    }

    return min ;
}
/*
int dist( point x1 , point x2 ){
    float dist = x1.x 
    sqrt() ;
}
*/
int main() {

    vector<point> points , final_set ;
    point leftMost , current , temp ;
/*
    points.push_back(point(1,1)) ;
    points.push_back(point(0,0)) ;
    points.push_back(point(2,3)) ;
    points.push_back(point(3,2)) ;
    points.push_back(point(-3,2)) ;
*/
    points.push_back(point(0,3)) ;
    points.push_back(point(2,2)) ;
    points.push_back(point(1,1)) ;
    points.push_back(point(2,1)) ;
    points.push_back(point(3,0)) ;
    points.push_back(point(0,0)) ;
    points.push_back(point(3,3)) ;
    points.push_back(point(4,4)) ;

    points.push_back(point(4,2)) ;    
  

    leftMost = getLeftMostEdge(points) ;
    current = leftMost ;

//    cout << isLeft(points[0] , points[2] , points[1] ) <<endl ;

//    cout << leftMost.x << " " << leftMost.y << endl ;

while(true) {
    cout << current.x << " "<<current.y << endl;  

    // now look at every other node and see which one is most left
    for(int i = 0 ; i < points.size() ; i++) {
        if(points[i] == current)
            continue ;
        temp = points[i] ;
    }

    for(int i = 0 ; i < points.size() ; i++) {
        if( isLeft(current , temp , points[i] ) == 1 ) {
            temp = points[i] ;
        }
    }
    
    if(temp == leftMost ) {
        break; 
    }
    current = temp ;
    
}




	return 0;
}