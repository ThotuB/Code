#include "graph.h"

void dijkstra(Graph G, unsigned start){
    G.graph[start]->distance = 0;

    priority_queue <puv, vector<puv>, greater<puv>> q;
    for (Vertex* vert : G.graph){
        q.push(puv(vert->distance, vert));
    }

    while ( !q.empty() ){
        Vertex* u = q.top().second;
        q.pop();

        for (auto vert : u->neighbors){
            Vertex* v = vert.first;
            unsigned w = vert.second;

            Graph::relax(u, v, w);
        }
    }
}

int main(){
    Graph graph( ifstream("data.txt") );
    dijkstra(graph, 0);
    graph.print();
}