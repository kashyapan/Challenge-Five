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
  vector<dj> lst ;
 	priority_queue<nd> pq ;
 	
  //All Nodes Created
  
    addEdge(adj, 0, 1 , 5);
    addEdge(adj, 0, 3 , 9);
    addEdge(adj, 0 , 5 , 2);
    addEdge(adj, 1, 2 , 2);
    addEdge(adj, 5, 4 , 3);
    addEdge(adj, 2, 3 , 3);
    addEdge(adj, 3, 4 , 2);
  
  for(int i = 0 ; i  <  V ;i++)  {
    lst.push_back(dj(i)) ;

  }
    
  lst[current].visited = true ;
  lst[current].dist = 0 ;
  lst[current].via = 0 ;
  

do {
  
  lst[current].visited = true ;
  lst[current].via = 0 ;
  
  cout << current << " -> "<< adj[current].size()  <<endl ;
  //Mark all neigh of source 
  
  for(int i = 0 ; i < adj[current].size() ; i++) {
    
    //Get all neigh weight and push in priority queue
    int xx = adj[current][i].vertex ;
  

    if( (lst[ xx ].dist  ) >  (adj[current][i].weight + lst[current].dist ) && lst[xx].visited == false ) {
      
      cout << "updating " << xx<< " " << lst[xx].dist << " to "<< (adj[current][i].weight + lst[current].dist) <<endl;
      lst[xx].dist = adj[current][i].weight + lst[current].dist ;
      lst[xx].via = current ;
      int wx = lst[xx].dist ;

      cout << "pushing "<<xx << " with weight "<<wx << endl ;
      pq.push(nd(xx ,wx)) ;
    }
      
      
  }

  current = pq.top().vertex ;  
  pq.pop() ;
  
}  while(! pq.empty() ) ;


for(int  i = 0 ; i < V ; i++)
  cout << lst[i].vertex << " " << lst[i].dist <<endl ; 

	return 0;
}