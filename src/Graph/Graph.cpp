#include "Graph/Graph.h"

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
    for (int i = 0; i < nSize; i++) {
        vertices[i].first = rand() % (nSize + 1);
        vertices[i].second = rand() % (nSize + 1);
    }
}

void Graph::GenerateArestas() {
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
        }
    }
}