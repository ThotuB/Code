#include "graph.h"

unsigned time;

void dfs_visit(Graph G, Vertex* u){
    u->timeDiscovery = ++time;
    u->visited = true;

    u->print();

    for (Vertex* v : u->neighbors){
        if ( !v->visited ){
            v->predecessor = u;
            dfs_visit(G, v);
        }
    }
    u->timeFinish = ++time;

    u->print();
}

void dfs(Graph G){
    time = 0;
    for (Vertex* u : G.graph){
        if ( !u->visited ){
            dfs_visit(G, u);
        }
    }
}

int main(){
    Graph graph(ifstream("data.txt"));
    dfs(graph);
}