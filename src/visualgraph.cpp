
#include<iostream>
#include"deps/graph.cpp"
//#include"deps/drawlines.cpp"
#include"visualize.cpp"
#include<fstream>
using namespace std;

int main(void){
  Graph g = Graph("../resources/Graph8.txt","../resources/xycoords",Graph::undirected);
  Visualize v = Visualize(g);

  return 0;
}
