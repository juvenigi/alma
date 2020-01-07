/* Equality & Inequality */

// TODO:
// implement proper classes or structs as a replacement for ad-hoc ints and vectors
// (improves readiblity and is overall good style)
// modularize code (better reusability
// create proper headers and automate header generation (some emacs fuckery)
// figure out how to get cmake to work

// I want to know how dependent .o files get mashed together into an executable)
// (on one hand, this is something that happens automagically, I can probably avoid using cmake altogether
// what I can possibly do is to simply glob all .o files and run g++ to compile each time
// possibly a terrible idea that might just work.
// essentially, we're re-inventing the wheel in this case.

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include"deps/graph.cpp"

using namespace std;

vector<int> neint(Graph & g, int nodeid){
  vector<int> result;
  auto node = g.get_node(nodeid);
  auto neigbors = node.adjacent_nodes();
  for(auto i : neigbors){
    result.push_back(i.id());
  }
  return result;
}

set<int> bfs(Graph &g, int start){

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
    neidq.pop();
    if(neidq.size()){
      curnode = g.get_node(neidq.front());
      neids = neint(g, neidq.front());
    }
  }
  return neidset;
}

void vec_init(vector<int> & vec, Graph & g, int nodeid){
  set<int> b = bfs(g, nodeid);
  b.erase(nodeid); // prevent paradoxes where i != i
  for(auto n : b){
    vec.push_back(n);
  }
}

void neq_init(vector<int> & vec, Graph &g, int nodeid){
  for(auto n : g.get_node(nodeid).adjacent_nodes()){
    vec.push_back(n.id());
  }
}

int main(void){
  Graph eq = Graph("../resources/gleichungen.txt", Graph::undirected);
  Graph neq = Graph("../resources/ungleichungen.txt", Graph::directed);
  //Graph eq = Graph("../resources/gtest.txt", Graph::undirected);
  //Graph neq = Graph("../resources/gtest2.txt", Graph::directed);

  int nodes = eq.num_nodes(); // possibly use size_t to prevent possible overflow

  vector<int> equals;
  vector<int> nquals;
  vector<pair<int,int>> paradox;
  paradox.reserve(nodes);

  set<int> nids;
  for(int i = 0; i<nodes; i++){
    nids.insert(i);
  }

  for(int it = 0;nids.size()!=0;){

    vec_init(equals, eq, it);
    equals.push_back(it);

    for(int eq : equals){
      neq_init(nquals, neq, eq);
      for(int e : equals){
        //vec_init(nquals, neq, e);
        for(int n : nquals){
          if(e==n) {
            paradox.push_back(make_pair(eq,n));
          }
        }
      }
      nquals.clear();
      }
    for(auto i : equals){
      nids.erase(i);
    }
    nids.erase(it);
    it =  *nids.begin();

    equals.clear();
    //nquals.clear();
  }
  for (auto i : paradox){
    cout << "Es gibt Weg von: " << i.first << " zu " << i.second << " in G aber die sind nach U ungleich" <<endl;

    cout << "Nachbaren von " << i.first << ":"<<endl;
    for(auto n : eq.get_node(i.first).adjacent_nodes())
      cout << n.id() << " ";
    cout <<endl
         << "Nachbaren von " << i.second <<":"<<endl;
    for(auto n : eq.get_node(i.second).adjacent_nodes())
      cout << n.id() << " ";
    cout <<endl;

    // cout << "Zusammenhangskomponenten von " << i.first <<": "<<endl;
    // for(auto q : bfs(eq,i.first)){
    //   cout << q << " ";
    // }
    // cout <<endl;
    // for(auto q : bfs(neq,i.first)){
    //   cout << q << " ";
    // }
    // cout <<endl;
    //         << "Verbindungen: " << i.first
  }
  return 0;
}
