#include "Graph/Graph.h"
#include <fstream>

Graph::Graph(int _nSize, int _kSize) {

    nSize = _nSize;
    kSize = _kSize;

    vertices = std::vector<std::pair<int, int>>(nSize, std::pair<int, int>());
    arestas =
        std::vector<std::map<int, double>>(nSize, std::map<int, double>());

    GenerateVertices();
    GenerateArestas();
}

void Graph::GenerateVertices() {
    std::fstream fs;
    fs.open("steplog/vertices.log", std::fstream::out);

    for (int i = 0; i < nSize; i++) {
        vertices[i].first = rand() % (nSize + 1);
        vertices[i].second = rand() % (nSize + 1);
        fs << vertices[i].first << " " << vertices[i].second << std::endl;
    }
}

void Graph::GenerateArestas() {
    std::fstream fs;
    fs.open("steplog/arestas.log", std::fstream::out);

    for (int i = 0; i < nSize; i++) {
        for (int k = 0; k < kSize; k++) {

            int verticeConnection;
            do {
                verticeConnection = rand() % (nSize);
            } while (verticeConnection == i &&
                     arestas[i].count(verticeConnection) > 0);

            double distance =
                GetDistance(vertices[i], vertices[verticeConnection]);

            arestas[i].insert({verticeConnection, distance});
            arestas[verticeConnection].insert({i, distance});

            fs << i << " " << verticeConnection << std::endl;
        }
    }
}