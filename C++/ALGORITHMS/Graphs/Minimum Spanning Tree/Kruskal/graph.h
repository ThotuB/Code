#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Vertex {
public:
    unsigned index;
    bool visited;

public:
    Vertex(){}

    Vertex(unsigned _index){
        index = _index;
        visited = false;
    }

    void print(){
        cout << "Vertex " << index << "\n";
    }
};

typedef pair<unsigned, pair<Vertex*, Vertex*>> edge_t;

class Graph {
private:
    unsigned size;
    vector <Vertex*> graph;
    unsigned **distances;

    void init_distances(){
        distances = new unsigned*[size];
        for (unsigned i = 0 ; i < size ; i++){
            distances[i] = new unsigned[size];
            for (unsigned j = 0 ; j < size ; j++){
                distances[i][j] = 0;
            }
        }
    }

public:
    Graph(ifstream file){
        file >> size;
        init_distances();
        for (unsigned i = 0 ; i < size ; i++){
            graph.push_back(new Vertex(i));
        }

        unsigned u, v, w;
        while ( file >> u >> v >> w ){
            distances[u][v] = w;
            distances[v][u] = w;
        }
    }

    void print(){
        for (Vertex* v : graph){
            v->print();
        }
    }

    friend void kruskal(Graph);
};