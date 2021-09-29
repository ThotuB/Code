#include "graph.h"

void prim_vertex(Graph G, Vertex* u, priority_queue <edge_t, vector<edge_t>, greater<edge_t>> &q){
    u->visited = true;

    for (unsigned i = 0 ; i < G.size ; i++){
        if ( G.distances[u->index][i] != 0 ){
            q.push( edge_t( G.distances[u->index][i], pair<Vertex*, Vertex*>( G.graph[u->index], G.graph[i] ) ) );
        }
    }
}

void prim(Graph G, unsigned start){
    priority_queue <edge_t, vector<edge_t>, greater<edge_t>> q;
    prim_vertex(G, G.graph[start], q);

    while ( !q.empty() ){
        edge_t edge = q.top();
        q.pop();

        Vertex* u = edge.second.first;
        Vertex* v = edge.second.second;

        if ( !v->visited ){
            cout << u->index << " - " << v->index << "\n";
            prim_vertex(G, v, q);
        }
    }
}

int main(){
    Graph graph( ifstream("data.txt") );
    prim(graph, 0);
}