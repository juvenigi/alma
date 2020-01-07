// graph.h (Declaration of Class Graph)
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph {
public:
    using NodeId = int;  // vertices are numbered 0,...,num_nodes()-1

    class Neighbor {
    public:
        Neighbor(Graph::NodeId n, double w);
        double edge_weight() const;
        Graph::NodeId id() const;
    private:
        Graph::NodeId _id;
        double _edge_weight;
    };

    class Node {
    public:
        void add_neighbor(Graph::NodeId nodeid, double weight);
        const std::vector<Neighbor> & adjacent_nodes() const;
        // should probably follow the convention and make coordinates private, but I'm too bummed
        std::pair<double,double> coords;
    private:
        std::vector<Neighbor> _neighbors;
        //std::pair<double,double> _coords;
    };

    enum DirType {directed, undirected};  // enum defines a type with possible values
    Graph(NodeId num_nodes, DirType dirtype); // constructor without filename
    Graph(char const* filename, DirType dirtype); // constructor with input nodes
    Graph(char const* filename, char const* coordfile, DirType dirtype);

    void add_nodes(NodeId num_new_nodes);
    void add_edge(NodeId tail, NodeId head, double weight = 1.0);

    NodeId num_nodes() const;
    const Node & get_node(NodeId) const;
    void print() const;

    const DirType dirtype;
    static const NodeId invalid_node;
    static const double infinite_weight;

    std::pair<double,double> maxresolution; // maximum x and y values
    //std::pair<double,double> minresolution
private:
    std::vector<Node> _nodes;
    //std::vector<double> _maxresoultion; // x y coordinates
    //std::vector<double> _minresoultion; // x y coordinates
};

#endif // GRAPH_H
