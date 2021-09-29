#include "graph.h"

unsigned time;

void dfs_visit_ap(Graph G, Vertex* u){
    u->timeDiscovery = ++time;
    u->visited = true;
    u->low = u->timeDiscovery;

    unsigned sons = 0;
    for (Vertex* v : u->neighbors){
        sons++;
        if ( !v->visited ){
            v->predecessor = u;
            dfs_visit_ap(G, v);
            if ( u->predecessor == NULL ){
                if ( sons == 2 ) {
                    u->print();                         // CASE I
                    cout << "ARTICULATION POINT\n";
                }
            }
            else {
                u->low = min(u->low, v->low);
                if ( v->low >= u->timeDiscovery ){
                    u->print();                         // CASE II
                    cout << "ARTICULATION POINT\n";
                }
            }
        }
        else if ( ( v != u->predecessor ) && ( v->timeDiscovery < u->timeDiscovery ) ){
            u->low = min(u->low, v->timeDiscovery);
        }
    }
    u->timeFinish = ++time;
}

void dfs(Graph G){
    time = 0;
    for (Vertex* u : G.graph){
        if ( !u->visited ){
            dfs_visit_ap(G, u);
        }
    }
}

int main(){
    Graph graph(ifstream("data.txt"));
    dfs(graph);
}