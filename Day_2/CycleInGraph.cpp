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
  int V = 4 ;
  int source = 0 ;
  int current = source ;

  vector<nd> adj[V];
  vector<int> sets(V , -1) ;
  
  addEdge(adj, 0, 1 , 0);
  addEdge(adj, 0, 2 , 0);
  //addEdge(adj, 1 , 2 , 0 );
//  addEdge(adj, 2 ,3 , 0 );
  addEdge(adj, 0 ,3 , 0 );  
  
  //All Nodes Created
  

 // viewList(adj , V) ;

  for(int i = 0 ; i < V ; i++) {

    for(int j = 0 ; j < adj[i].size() ; j++) {
      unionSets(sets , i , adj[i][j].vertex ) ;
    }
    
    cout << endl ;
  }


	return 0;
}
