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

public:
    Vertex(){}

    Vertex(unsigned _index){
        index = _index;
        distance = INF;
    }

    void print(){
        cout << "Vertex " << index << " - " << distance << "\n";
    }
};

typedef pair<unsigned, Vertex*> puv;

class Graph {
private:
    unsigned size;
    vector <Vertex*> graph;
    int **distances;

    void init_distances(){
        distances = new int*[size];
        for (unsigned i = 0 ; i < size ; i++){
            distances[i] = new int[size];
            for (unsigned j = 0 ; j < size ; j++){
                distances[i][j] = INF;
            }
        }
        for (unsigned i = 0 ; i < size ; i++){
            distances[i][i] = 0;
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

    friend void floyd_warshall(Graph);
};