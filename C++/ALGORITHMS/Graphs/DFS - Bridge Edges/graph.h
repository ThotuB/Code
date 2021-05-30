#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Vertex {
public:
    unsigned index;

    unsigned timeDiscovery;
    unsigned timeFinish;
    unsigned low;
    bool visited;
    Vertex* predecessor;

    vector <Vertex*> neighbors;

public:
    Vertex(){}

    Vertex(unsigned _index){
        index = _index;
        visited = false;
        predecessor = NULL;
        timeFinish = 0;
    }

    void add(Vertex* vertex){
        neighbors.push_back(vertex);
    }

    void print(){
        cout << "Vertex " << index << " (LOW = " << low << ") - " << timeDiscovery << "/" << timeFinish << "\n";
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

        unsigned u, v;
        while ( file >> u >> v ){
            graph[u]->add(graph[v]);
            graph[v]->add(graph[u]);
        }
    }

    friend void dfs_visit_ap(Graph, Vertex*);
    friend void dfs(Graph);
};