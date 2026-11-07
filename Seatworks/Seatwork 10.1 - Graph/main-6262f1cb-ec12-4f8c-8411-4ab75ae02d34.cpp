#include <iostream>
#include "GRAPH.H"

int main(){
    Graph g;

    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');

    g.addEdge('A', 'B', 3);
    g.addEdge('A', 'C', 2);
    g.addEdge('C', 'B', 1);
    g.addEdge('D', 'A', 4);

    std::cout << "Main Root Element: D" << std::endl; // I think the element D is the main root
    std::cout << std::endl;

    std::cout << g << std::endl;

    return 0;
}