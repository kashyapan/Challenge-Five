#include <bits/stdc++.h>
#define bigGuy 100000000 
#define modGuy 1000000007

using namespace std;

stack<int> stk ;

class nd {
  public :
  int vertex ; 
  int weight ;
  nd(int v , int w) {
    vertex = v ;
    weight = w ;
  }
} ;

void addEdge( vector<nd> *vec , int u , int v , int w) {
  vec[u].push_back(nd(v  ,w)) ;  
}

void viewList(vector<nd> *adj ,  int V) {
  

  for(int i = 0 ; i < V ; i++) {
    cout << i << " -- > " ;
    for(int j = 0 ; j < adj[i].size() ; j++) {
      cout << adj[i][j].vertex << " - ";
    }
    
    cout << endl ;
  }
}

void topoSort(vector<nd> *vec , vector<bool> &visited , int key ) {

 
  //visit all its neighburs
  visited[key] = true ;

  for(int i = 0  ; i < vec[key].size() ; i++ ){
    int neigh = vec[key][i].vertex ;

    //now see if it is already visited

    if(visited[neigh] == false) {
      visited[neigh] = true ;
      topoSort(vec , visited , neigh);
    }
  }

  //If no neigh or visited all neigh comes here

  //add it to stack
  stk.push(key) ; 

}

int main() {


  //Number of vertices is given
  int V = 7 ;
  int source = 0 ;
  int current = source ;

  vector<nd> adj[V];
  vector<bool> visited(V , false) ;
  
  addEdge(adj, 0, 2 , 3);
  addEdge(adj, 1, 2 , 1);
  addEdge(adj, 2 ,3 , 3 );  
  addEdge(adj, 3 ,5 , 1 );    
  addEdge(adj, 1 ,4 , 1 );  
  addEdge(adj, 4 ,5 , 6 );  
  addEdge(adj, 5 ,6 , 2 );  
  
  //All Nodes Created

//  viewList(adj , V) ;
  for(int i = 0 ; i < visited.size() ; i++ ) {
    
     //If already visited skip;
    if(visited[i] == true)
      continue ;

    topoSort(adj , visited , i) ;
      
  }

//Print topological sort
  while( ! stk.empty() ){
    cout << stk.top() << " " ;
    stk.pop() ;
  }

	return 0;
}