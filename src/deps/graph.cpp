// graph.cpp (Implementation of Class Graph)

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
//#include <algorithm>
#include "graph.h"

const Graph::NodeId Graph::invalid_node = -1;
const double Graph::infinite_weight = std::numeric_limits<double>::max();


void Graph::add_nodes(NodeId num_new_nodes)
{
    _nodes.resize(num_nodes() + num_new_nodes);
}

Graph::Neighbor::Neighbor(Graph::NodeId n, double w): _id(n), _edge_weight(w) {}

Graph::Graph(NodeId num, DirType dtype): dirtype(dtype), _nodes(num) {}

void Graph::add_edge(NodeId tail, NodeId head, double weight)
{
    if (tail >= num_nodes() or tail < 0 or head >= num_nodes() or head < 0) {
        throw std::runtime_error("Edge cannot be added due to undefined endpoint.");
    }
    _nodes[tail].add_neighbor(head, weight);
    if (dirtype == Graph::undirected) {
        _nodes[head].add_neighbor(tail, weight);
    }
}

void Graph::Node::add_neighbor(Graph::NodeId nodeid, double weight)
{
    _neighbors.push_back(Graph::Neighbor(nodeid, weight));
}

const std::vector<Graph::Neighbor> & Graph::Node::adjacent_nodes() const
{
    return _neighbors;
}

Graph::NodeId Graph::num_nodes() const
{
    return _nodes.size();
}

const Graph::Node & Graph::get_node(NodeId node) const
{
    if (node < 0 or node >= static_cast<int>(_nodes.size())) {
        throw std::runtime_error("Invalid nodeid in Graph::get_node.");
    }
    return _nodes[node];
}

Graph::NodeId Graph::Neighbor::id() const
{
    return _id;
}

double Graph::Neighbor::edge_weight() const
{
    return _edge_weight;
}

void Graph::print() const
{
    if (dirtype == Graph::directed) {
        std::cout << "Digraph ";
    } else {
        std::cout << "Undirected graph ";
    }
    std::cout << "with " << num_nodes() << " vertices, numbered 0,...,"
              << num_nodes() - 1 << ".\n";

    for (auto nodeid = 0; nodeid < num_nodes(); ++nodeid) {
        std::cout << "The following edges are ";
        if (dirtype == Graph::directed) {
            std::cout << "leaving";
        } else {
            std::cout << "incident to";
        }
        std::cout << " vertex " << nodeid << ":\n";
        for (auto neighbor: _nodes[nodeid].adjacent_nodes()) {
            std::cout << nodeid << " - " << neighbor.id()
                      << " weight = " << neighbor.edge_weight() << "\n";
        }
    }
}

Graph::Graph(char const * filename, DirType dtype): dirtype(dtype)
{
    std::ifstream file(filename);                             // open file
    if (not file) {
        throw std::runtime_error("Cannot open file.");
    }

    Graph::NodeId num = 0;
    std::string line;
    std::getline(file, line);                 // get first line of file
    std::stringstream ss(line);               // convert line to a stringstream
    ss >> num;                                // for which we can use >>
    if (not ss) {
        throw std::runtime_error("Invalid file format.");
    }
    add_nodes(num);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Graph::NodeId head, tail;
        ss >> tail >> head;
        if (not ss) {
            throw std::runtime_error("Invalid file format.");
        }
        double weight = 1.0;
        ss >> weight;
        if (tail != head) {
            add_edge(tail, head, weight);
        }
        else {
            throw std::runtime_error("Invalid file format: loops not allowed.");
        }
    }
}

//static std::pair<double,double> Graph::maxresoulion;

Graph::Graph(char const * filename, char const * coords, DirType dtype): dirtype(dtype)
{
  std::ifstream file(filename);                             // open file
  if (not file) {
    throw std::runtime_error("Cannot open file.");
  }
  std::ifstream cfile(coords);
  if (not cfile) {
    throw std::runtime_error("Cannot open coordinates file.");
  }


  // The first line of a Graph.txt file is the amount of nodes, therefore this happens
  Graph::NodeId num = 0;
  std::string line;
  std::getline(file, line);                 // get first line of file
  std::stringstream ss(line);               // convert line to a stringstream
  ss >> num;                                // for which we can use >>
  if (not ss) {
    throw std::runtime_error("Invalid file format.");
    }
  add_nodes(num);

  // The rest of the file follows a very standard convention
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    Graph::NodeId head, tail;
    ss >> tail >> head;
    if (not ss) {
      throw std::runtime_error("Invalid file format.");
    }
    double weight = 1.0;
    ss >> weight;
    if (tail != head) {
      add_edge(tail, head, weight);
    }
    else {
      throw std::runtime_error("Invalid file format: loops not allowed.");
    }
  }

  //FIXME: probably need to comment this out because it won't work correctly the first time
  // int ccount = std::count(std::istreambuf_iterator<char>(cfile),
  //                        std::istreambuf_iterator<char>(), '\n');
  // if(ccount != Graph::num_nodes()){
  //   throw std::runtime_error("not enough xy coord entries");
  // }

  // Initialize coordinates for each node
  double mx,my = 0;
  for (int n = 0; n < Graph::num_nodes(); n++){
    std::getline(cfile, line);
    std::stringstream ss(line);
    double x,y;
    ss >> x >> y;
    _nodes[n].coords = std::make_pair(x,y);
    if(x>mx){mx = x;}
    if(y>my){my = y;}
  }
  maxresolution = std::make_pair(mx,my);
}

// debug
// int main(void){return 0;}
