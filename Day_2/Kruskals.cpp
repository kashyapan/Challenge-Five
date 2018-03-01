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
} ;

int findSet(vector<int> &vec , int key) {
  
  if(vec[key] == -1)
    return key ;
    
  findSet(vec , vec[key]) ;
  
}

void unionSets(vector<int> &vec , int x , int y) {
  int set_x = findSet(vec , x);
  int set_y = findSet(vec , y);
  
  if(set_x == set_y) {
    cout << "You guys are in cycle" <<endl ;
    return ;
  }
  
  cout << "Good to go " <<endl ;
  
  vec[set_y] = set_x ;
  
}


void addEdge( vector<nd> *vec , int u , int v , int w) {
  
  vec[u].push_back(nd(v  ,w)) ;
 // vec[v].push_back(nd(u  ,w)) ;
  
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
int main() {


  //Number of vertices is given
  int V = 6 ;
  int source = 0 ;
  int current = source ;

  vector<nd> adj[V];
  vector<int> sets(V , -1) ;
  vector<edge> edges ;
  vector<edge> mst ;
  
  addEdge(adj, 0, 1 , 3);
  addEdge(adj, 0, 3 , 1);
  addEdge(adj, 1 ,3 , 3 );  
  addEdge(adj, 1 ,2 , 1 );    
  addEdge(adj, 3 ,2 , 1 );  
  addEdge(adj, 3 ,4 , 6 );  
  addEdge(adj, 2 ,4 , 5 );
  addEdge(adj, 2 ,5 , 4 );
  addEdge(adj, 4 ,5 , 2 );  
  
  //All Nodes Created
  
  for(int i = 0 ; i < V ; i++) {
    for(int j = 0 ; j < adj[i].size() ; j++) {
        int xx  =  adj[i][j].vertex  ;
        int wx  =  adj[i][j].weight  ;
        edges.push_back(edge( i , xx ,wx )) ;
    }
  }

  sort(edges.begin() , edges.end()  , [](const edge &lhs , const edge &rhs){ return lhs.w < rhs.w; } ) ;

  for(int i = 0 ; i < edges.size() ; i++) {
      //cout << edges[i].u <<" "<< edges[i].v <<" "<< edges[i].w <<endl ;

      int set_u = findSet(sets ,edges[i].u ) ;
      int set_v = findSet(sets ,edges[i].v ) ;

      if( set_u != set_v ) {

          mst.push_back ( edges[i] ) ;
          sets[set_u] = set_v ;
      }
      
  }

  for(int i = 0 ; i < mst.size() ; i++) {
      cout << mst[i].u <<" "<< mst[i].v <<" "<< mst[i].w <<endl ;

      
  }  

 // viewList(adj , V) ;
/*
  for(int i = 0 ; i < V ; i++) {
    for(int j = 0 ; j < adj[i].size() ; j++) {
      unionSets(sets , i , adj[i][j].vertex ) ;
    }
     cout << endl ;
  }
*/

	return 0;
}