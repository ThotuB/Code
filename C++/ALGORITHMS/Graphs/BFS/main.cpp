#include "graph.h"

void bfs(Graph G, unsigned start){
    G.graph[start]->distance = 0;
    G.graph[start]->visited = true;

    queue <Vertex*> q;
    q.push(G.graph[start]);

    while ( !q.empty() ){
        Vertex* u = q.front();

        u->print();

        q.pop();
        for (Vertex* v : u->neighbors){
            if ( !v->visited ){
                v->visited = true;
                v->distance = u->distance + 1;
                v->predecessor = u;
                
                q.push(v);
            }
        }
    }
}

void print_path(Graph G, unsigned start, unsigned curr){
    if ( start == curr ){
        cout << start << " ";
    }
    else if ( G.graph[curr]->predecessor == NULL ){
        cout << "PATH ERROR FROM <" << start << "> TO <" << curr << ">\n";
    }
    else {
        print_path(G, start, G.graph[curr]->predecessor->index);
        cout << curr << " ";
    }
}

int main(){
    Graph graph(ifstream("data.txt"));
    bfs(graph, 1);
    print_path(graph, 1, 7);
}