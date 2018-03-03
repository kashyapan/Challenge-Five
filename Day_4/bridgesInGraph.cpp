#include <bits/stdc++.h>
#define bigGuy 100000000 
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

class edge {
public :
  int u , v ; 
  int w ;
  edge(int u , int v , int weight) {
    this->v = v ;
    this->u = u ;
    this->w = weight ;
  }

  edge(int u , int v ) {
    this->v = v ;
    this->u = u ;
    this->w = 0 ;
  }
} ;

void addEdge( vector<nd> *vec , int u , int v , int w) {
  
  vec[u].push_back(nd(v  ,w)) ;
  vec[v].push_back(nd(u  ,w)) ;
  
}

void viewList(vector<nd> *adj ,  int V) {
  

  for(int i = 0 ; i < V ; i++) {
    cout << i << " -- > " ;
    for(int j = 0 ; j < adj[i].size() ; j++) {
      cout << adj[i][j].vertex << " "<< adj[i][j].weight << " | ";
    }
    
    cout << endl ;
  }
}



bool isThereBridge(vector<nd> *adj , int V , edge e )  {

    //Edge e is tested if it is  a bridge
    

    stack<int> s ;
    vector<bool> visited(V , false) ;
    int current = 0 ;
    
    s.push(current) ;
    visited[current] = true ;

//    cout << " u = " << e.u << " v = " << e.v <<endl ;

    while(! s.empty() )  {

        current = s.top() ;
        //cout << current <<" " ;
        s.pop() ;

        //push all neigh nodes
        for( int i = 0 ; i < adj[current].size() ; i++) {
            int x = adj[current][i].vertex ;

            //Disabling the "potential edge"

            if( (e.u == current && e.v == x ) || (e.u == x && e.v == current ) ) {
                continue ;
            }

            if( visited[x] == false ) {
                s.push( x ) ; 
                visited[x] = true ;
            }
                
        }

    }

    for(int i = 0 ; i < visited.size() ; i++ ) {
        if(visited[i] == false) return true ;
    }

    return false ;
}
int main() {


  //Number of vertices is given
  int V = 5 ;
  int source = 0 ;
  int current = source ;
  bool res ;
  vector<nd> adj[V];

  /*
  addEdge(adj, 0, 1 , 0);
  addEdge(adj, 0, 2 , 0);
  addEdge(adj, 0, 3 , 0);
  addEdge(adj, 1 , 2 , 0 );
  addEdge(adj, 3 ,4 , 0 );  
  */
  addEdge(adj, 0, 1 , 0);
  addEdge(adj, 1, 2 , 0);
  addEdge(adj, 2, 3 , 0);


  //All Nodes Created
  

//  viewList(adj , V) ;


    for(int i = 0 ; i < V ; i++) {
        
        for(int j = 0 ; j < adj[i].size() ; j++) {
            int vtx = adj[i][j].vertex ;

            res = isThereBridge(adj , V , edge(i ,vtx)) ;        
            
            if(res == true ) {
                cout << i<<" "<< vtx<<endl ;
            }
        }

    }


	return 0;
}
