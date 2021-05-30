#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define INF 10000

class Vertex {
public:
    unsigned index;
    unsigned distance;
    vector <pair<Vertex*, int>> neighbors;

public:
    Vertex(){}

    Vertex(unsigned _index){
        index = _index;
        distance = INF;
    }

    void add(Vertex* vertex, int weight){
        neighbors.push_back(pair<Vertex*, int>(vertex, weight));
    }

    void print(){
        cout << "Vertex " << index << " - " << distance << "\n";
        for (auto n : neighbors){
            cout << " -> " << n.first->index << " - " << n.second << "\n";
        }
    }
};

typedef pair<unsigned, Vertex*> puv;

class Graph {
private:
    vector <Vertex*> graph;

public:
    Graph(ifstream file){
        unsigned size;
        file >> size;
        for (unsigned i = 0 ; i < size ; i++){
            graph.push_back(new Vertex(i));
        }

        unsigned u, v, w;
        while ( file >> u >> v >> w ){
            graph[u]->add(graph[v], w);
        }
    }

    void reset(){
        for (Vertex* v : graph){
            v->distance = INF;
        }
    }
    
    static void relax(Vertex* u, Vertex* v, int w){
        if ( v->distance > u->distance + w ){
            v->distance = u->distance + w;
        }
    }

    void print(){
        for (Vertex* v : graph){
            v->print();
        }
    }

    friend bool bellman_ford(Graph, unsigned);
};