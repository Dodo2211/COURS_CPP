#include"graph.hpp"


int main(){
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_edge(0,0,1);
    //g.add_edge(0,0,5.2);
    g.add_edge(0,1,0.2); 
    g.add_edge(0,2,0.3);
    g.add_edge(1,0,3.2);
    g.add_edge(1,2,3);
    g.add_edge(3,4,0.2);
    g.deep_search();
    g.print();
    g.print_graph();
    
    return(0);
}
