#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>

class Vertex{
public:
    char id;
    std::map<char, int> connectedTo;

    // Constructor
    Vertex(){}

    // Constructor that defines the ID of the vertex
    Vertex(char key){
        id = key;
    }

    // Adds a neighbor with its weight
    void addNeighbor(char nbr, int weight = 0){
        connectedTo[nbr] = weight;
    }

    // Returns all vertices connected to this vertex
    std::vector<char> getConnections(){
        std::vector<char> keys;

        for (std::map<char, int>::iterator it = connectedTo.begin();
            it != connectedTo.end();
            ++it){
            keys.push_back(it->first);
        }
        return keys;
    }

    // Returns the ID of the vertex
    char getId(){
        return id;
    }

    // Returns the weight of the connection
    int getWeight(char nbr){
        return connectedTo[nbr];
    }

    // Output stream overload
    friend std::ostream& operator<<(std::ostream&, Vertex&);
};


// Prints the connections of a vertex
std::ostream& operator<<(std::ostream& stream, Vertex& vert){
    std::vector<char> connects = vert.getConnections();

    for (unsigned int i = 0; i < connects.size(); i++){
        stream << "(";
        stream << vert.id;
        stream << ", ";
        stream << connects[i];
        stream << ") Weight: ";
        stream << vert.getWeight(connects[i]);
        stream << std::endl;
    }
    return stream;
}

class Graph{
public:
    std::map<char, Vertex> vertList;
    int numVertices;

    // Constructor
    Graph(){
        numVertices = 0;
    }

    // Adds a vertex
    Vertex addVertex(char key){
        numVertices++;

        Vertex newVertex = Vertex(key);

        vertList[key] = newVertex;

        return newVertex;
    }

    // Returns the vertex with the specified ID
    Vertex* getVertex(char n){
        std::map<char, Vertex>::iterator it = vertList.find(n);

        if (it != vertList.end()){
            return &it->second;
        }

        return NULL;}

    // Checks if a vertex exists
    bool contains(char n){
        return vertList.find(n) != vertList.end();
    }

    // Adds a directed edge with a weight
    void addEdge(char f, char t, int cost = 0){
        if (!contains(f)){
            std::cout << f << std::endl;
            std::cout << " was not found, adding!";
            std::cout << std::endl;

            addVertex(f);
    }

        if (!contains(t)){
            std::cout << t << std::endl;
            std::cout << " was not found, adding!" << std::endl;
            std::cout << std::endl;

            addVertex(t);
        }

        vertList[f].addNeighbor(t, cost);
    }

    // Returns all vertices in the graph
    std::vector<char> getVertices(){
        std::vector<char> verts;

        for (std::map<char, Vertex>::iterator it = vertList.begin();
             it != vertList.end();
             ++it){
            verts.push_back(it->first);
        }

        return verts;
    }

    // Output stream overload
    friend std::ostream& operator<<(std::ostream&, Graph&);
};


// Prints the graph
std::ostream& operator<<(std::ostream& stream, Graph& grph){
    for (std::map<char, Vertex>::iterator it = grph.vertList.begin();
         it != grph.vertList.end();
         ++it){
        stream << it->second;
    }

    return stream;
}

#endif