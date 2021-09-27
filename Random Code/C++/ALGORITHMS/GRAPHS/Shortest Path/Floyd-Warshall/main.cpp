#include "graph.h"

void floyd_warshall(Graph G){
    for (unsigned k = 0 ; k < G.size ; k++){
        for (unsigned i = 0 ; i < G.size ; i++){
            for (unsigned j = 0 ; j < G.size ; j++){
                G.distances[i][j] = min(G.distances[i][j], G.distances[i][k] + G.distances[k][j]);
            }
        }
    }
}

int main(){
    Graph graph( ifstream("data.txt") );
    floyd_warshall(graph);
    graph.print();
}