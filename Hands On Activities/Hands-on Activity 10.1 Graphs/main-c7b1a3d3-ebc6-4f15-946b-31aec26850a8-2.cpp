#include <iostream>
#include "GRAPH.H"
#include "ILOB1_DFS.H"
#include "ILOB2_BFS.H"

int main(){

    // A.2 Adjacency Matrix
    MatrixGraph graph;
// Undirected Graph
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');

    graph.addEdge('A', 'C');
    graph.addEdge('A', 'D');
    graph.addEdge('A', 'B');
    graph.addEdge('B', 'E');
    graph.addEdge('C', 'D');
    graph.addEdge('D', 'E');
 
    std::cout << "A2 - Adjacency Matrix" << std::endl;
    graph.displayMatrix();


    MatrixGraph weightedGraph;
// Weighted Graph
    weightedGraph.addVertex('A');
    weightedGraph.addVertex('B');
    weightedGraph.addVertex('C');
    weightedGraph.addVertex('D');
    weightedGraph.addVertex('E');

    weightedGraph.addWeightedEdge('A', 'B', 4);
    weightedGraph.addWeightedEdge('A', 'C', 3);
    weightedGraph.addWeightedEdge('C', 'D', 2);
    weightedGraph.addWeightedEdge('D', 'E', 1);
    weightedGraph.addWeightedEdge('D', 'B', 1);
    weightedGraph.addWeightedEdge('E', 'A', 1);

    std::cout << "A2 - Weighted Adjacency Matrix" << std::endl;
    weightedGraph.displayWeightedMatrix();

    Graph g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');

    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');

    std::cout << std::endl;
    std::cout << "A3 - Adjacency List" << std::endl;
    std::cout << std::endl;

    g.display();


    // A.3 - Adjacency List

    DirectedGraph directedGraph;
//Undurected / Directed Graph
    directedGraph.addVertex('A');
    directedGraph.addVertex('B');
    directedGraph.addVertex('C');
    directedGraph.addVertex('D');
    directedGraph.addVertex('E');

    directedGraph.addEdge('A', 'B');
    directedGraph.addEdge('A', 'C');
    directedGraph.addEdge('B', 'E');
    directedGraph.addEdge('C', 'D');
    directedGraph.addEdge('D', 'B');
    directedGraph.addEdge('D', 'E');

    std::cout << std::endl;
    std::cout << "\nA3 - Directed Graph Adjacency List\n";
    std::cout << std::endl;

    directedGraph.display();

// ILO B1
    //DFS File Code
    GraphList<unsigned> G = create_DFS_graph<unsigned>();

    std::cout << "Graph:\n";
    std::cout << G << std::endl;

    std::cout << "Recursive DFS Order of vertices: ";
    std::vector<size_t> order = recursive_DFS(G, 1);
    for (size_t v : order)
        std::cout << v << " ";

    std::cout << "\nIterative DFS Order of vertices: ";
    order = iterative_DFS(G, 1);
    for (size_t v : order)
        std::cout << v << " ";


//ILO B2
    //BFS File Code
    G = create_BFS_graph<unsigned>();
    order = bfs(G, 1);

    std::cout << "Graph:\n";
    std::cout << G << std::endl;

    std::cout << "BFS Order of vertices: ";

    for (size_t v : order)
        std::cout << v << " ";


    return 0;

}
