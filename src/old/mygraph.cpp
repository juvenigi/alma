#include<iostream>
#include<set>
#include<queue>
#include "graph.cpp" // lazy way

using namespace std;
using NodeId = int;

void printn(Graph g, NodeId nodeid){
  auto node = g.get_node(nodeid);
  auto neigbors = node.adjacent_nodes();
  for(auto i : neigbors){
    cout << i.id() << " ";
  }
  cout << endl;
}

vector<int> neint(Graph g, NodeId nodeid){
  vector<int> result;
  auto node = g.get_node(nodeid);
  auto neigbors = node.adjacent_nodes();
  for(auto i : neigbors){
    result.push_back(i.id());
  }
  return result;
}

void bfs(Graph * m, NodeId start){
  Graph g = *m;
  auto curnode = g.get_node(start);
  vector<int> neids = neint(g, start);

  set<int> neidset; // lists visited nodes
  queue<int> neidq; // queue to go through
  neidset.insert(start);
  neidq.push(start);

  while(neidq.size()){ // proceed if neidq is not empty
    for(auto i : neids){
      if(not neidset.count(i)) neidq.push(i);
      neidset.insert(i); // a new element is inserted when no duplicate exists
    }

    // dequeue
    cout << neidq.front() << " ";
    neidq.pop();

    // update values
    if(neidq.size()){
      curnode = g.get_node(neidq.front());
      neids = neint(g, neidq.front());
    }
  }
  cout << endl;
}

// void dfs(Graph m, NodeId start){
//   Graph g = *m;
//   auto curnode = g.get_node(start);
//   vector<int> neids = neint(g, start);
//   vector<int> sneids = neids;

//   set<int> neidset; // lists visited nodes
//   //vector<int> neidv; // queue to go through
//   neidset.insert(start);

//   bool all_ready = 1;
//   for(auto i : neids){
//     if(neidset.count(i)

    
//     // dequeue
//     cout << neidq.front() << " ";
//     neidq.pop();

//     // update values
//     if(neidq.size()){
//       curnode = g.get_node(neidq.front());
//       neids = neint(g, neidq.front());
//     }
//   }
//   cout << endl;
// }

int main(void){
  Graph g = Graph("../resources/Graph.txt",Graph::undirected);
  //g.print();
  printn(g,27);
  bfs(&g, 27);
  return 0;
}
