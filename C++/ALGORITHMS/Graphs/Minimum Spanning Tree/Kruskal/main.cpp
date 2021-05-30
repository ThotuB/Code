#include "graph.h"

void kruskal(Graph G){
    priority_queue <edge_t, vector<edge_t>, greater<edge_t>> q;
    for (unsigned i = 0 ; i < G.size ; i++){
        for (unsigned j = 0 ; j < G.size ; j++){  
            if ( G.distances[i][j] != 0 ){
                q.push( edge_t( G.distances[i][j], pair<Vertex*, Vertex*>( G.graph[i], G.graph[j] ) ) );
            }
        }
    }

    while ( !q.empty() ){
        edge_t edge = q.top();
        q.pop();

        Vertex* u = edge.second.first;
        Vertex* v = edge.second.second;

        if ( !v->visited ){
            cout << u->index << " - " << v->index << "\n";
            v->visited = true;
        }
    }
}

int main(){
    Graph graph( ifstream("data.txt") );
    kruskal(graph);
}