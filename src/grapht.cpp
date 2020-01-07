#include<iostream>
#include"deps/graph.cpp"

using namespace std;
int main(void){

  Graph g = Graph("../resources/gtest.txt",Graph::undirected);
  g.print();
  cout << "after messing around:" <<endl;
  g.add_edge(0,1,2.0);
  g.print();
  return 0;
}
