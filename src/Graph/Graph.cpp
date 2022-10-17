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
#ifdef LOGSTEP
    fs.open("steplog/vertices.log", std::fstream::out);
#endif

    for (int i = 0; i < nSize; i++) {
        vertices[i].first = rand() % (nSize + 1);
        vertices[i].second = rand() % (nSize + 1);
#ifdef LOGSTEP
        fs << vertices[i].first << " " << vertices[i].second << std::endl;
#endif
    }
}

void Graph::GenerateArestas() {
#ifdef LOGSTEP
    std::fstream fs;
    fs.open("steplog/arestas.log", std::fstream::out);
#endif

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
#ifdef LOGSTEP
            fs << i << " " << verticeConnection << std::endl;
#endif
        }
    }
}