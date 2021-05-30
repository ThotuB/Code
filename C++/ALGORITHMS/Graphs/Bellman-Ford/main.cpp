#include "graph.h"

bool bellman_ford(Graph G, unsigned start){
    G.graph[start]->distance = 0;
    for (unsigned i =  0 ; i < G.graph.size() - 1 ; i++){
        for (Vertex* u : G.graph){
            for (auto edge : u->neighbors){
                Vertex* v = edge.first;
                int w = edge.second;

                Graph::relax(u, v, w);
            }
        }
    }
    for (Vertex* u : G.graph){
        for (auto edge : u->neighbors){
            Vertex* v = edge.first;
            int w = edge.second;

            if ( v->distance > u->distance + w){
                return false;
            }
        }
    }
    return true;
}

int main(){
    Graph graph( ifstream("data.txt") );
    if ( !bellman_ford(graph, 0) ){
        cout << "DAMN\n";
        exit(1);
    }
    graph.print();
}