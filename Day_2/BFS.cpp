#include <bits/stdc++.h>
#define bigGuy 10000 
#define modGuy 1000000007

using namespace std;

class nd {
  public :
  int vertex ; 
  int weight ;
  nd(int v , int w) {
    vertex = v ;
    weight = w ;
  }
} ;


class dj {
  
  public :
  int vertex ;
  int dist ;
  int via ;
  bool visited ;
  
  dj(int ver ) {
    vertex = ver ;
    dist = bigGuy ;
    visited  = false ;
    via = -1 ;
  }
  
  
};


bool operator<(const nd &lhs , const nd &rhs){ 
    return lhs.weight > rhs.weight ;
}



void addEdge( vector<nd> *vec , int u , int v , int w) {
  
  vec[u].push_back(nd(v  ,w)) ;
  vec[v].push_back(nd(u  ,w)) ;
  
}

int main() {


  //Number of vertices is given
  
  int V = 6 ;
  int source = 0 ;
  int current = source ;
  
  //vector<int> edge[V] ;
  
  vector<nd> adj[V];
  vector<bool> visited(V , false) ;
  queue<int> q ; 

 	
  //All Nodes Created
  /*
    addEdge(adj, 0, 1 , 5);
    addEdge(adj, 0, 3 , 9);
    addEdge(adj, 0 , 5 , 2);
    addEdge(adj, 1, 2 , 2);
    addEdge(adj, 5, 4 , 3);
    addEdge(adj, 2, 3 , 3);
    addEdge(adj, 3, 4 , 2);
  */

    addEdge(adj, 0, 1 , 5);
    addEdge(adj, 0, 2 , 9);
    addEdge(adj, 1 , 3 , 2);
    addEdge(adj, 1, 4 , 2);
    addEdge(adj, 2, 4 , 3);    
    addEdge(adj, 3, 4 , 3);
    addEdge(adj, 3, 5 , 3);
    addEdge(adj, 4, 5 , 2);

    q.push(current) ;
    visited[current] = true ;


    while(! q.empty() )  {

        current = q.front() ;
        cout << current <<" " ;
        q.pop() ;

        //push all neigh nodes
        for( int i = 0 ; i < adj[current].size() ; i++) {
            int x = adj[current][i].vertex ;
            if( visited[x] == false ) {
                q.push( x ) ; 
                visited[x] = true ;
            }
                
        }

    }

    

	return 0;
}