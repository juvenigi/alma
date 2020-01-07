
#include<iostream>
//#include"deps/graph.cpp"
#include"deps/drawlines.cpp"
#include<fstream>
using namespace std;

class Visualize{
public:
  static unsigned int screen[1001][1001];    //static unsigned int screen[1001][1001]; // 1000 * 1000
  Visualize(Graph &g){
    for(unsigned int x = 0; x <= 1000; x++){
      for(unsigned int y = 0; y <= 1000; y++){
        Visualize::screen[x][y] = 255;
      }
    }

    //cout << g.get_node(10).coords.first << " " << g.get_node(10).coords.second <<endl;
    double xscale = 1000/g.maxresolution.first;
    double yscale = 1000/g.maxresolution.second;

    //cout << g.maxresolution.first << " " << g.maxresolution.second << endl;

    for(int o = 0; o<g.num_nodes();o++){
      for(auto n : g.get_node(o).adjacent_nodes()){
        int orix = g.get_node(o).coords.first * xscale;
        int oriy = g.get_node(o).coords.second * yscale;
        int neid = n.id();
      int neix = g.get_node(neid).coords.first * xscale;
      int neiy = g.get_node(neid).coords.second * yscale;
      //cout << orix << " " << oriy << " " << neix << " " << neiy << endl;
      line(orix,oriy,neix,neiy, screen);
      }

    }

    ofstream image;
    image.open("out.pgm");
    if(not image.is_open()){throw("file write error");}
    image << "P2" <<endl
        << "1000 1000" <<endl
          << 255 <<endl;
    for(size_t x = 0; x < 1001; x++){
      for(size_t y = 0; y < 1001; y++){
        image << screen[x][y] <<endl;
      }
    }
    image.close();}
  void redraw(int x0, int y0, int x1, int y1, int color){
    line(x0,y0,x1,y1, screen);
  }
};

unsigned int Visualize::screen[1001][1001];
