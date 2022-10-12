#include "Edge.h"
#include "PathFinderFactory.h"

#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <tuple>
#include <vector>

double GetDistance(std::tuple<int, int> x, std::tuple<int, int> y);

int main(int argc, char *argv[]) {
    // Setting random seed
    srand(time(NULL));

    int nSize = std::atoi(argv[1]);
    int kSize = std::atoi(argv[2]);
    int nTests = std::atoi(argv[3]);

    std::vector<std::tuple<int, int>> vertices(nSize, std::tuple<int, int>());

    std::vector<std::vector<Edge>> arestas(nSize, std::vector<Edge>(kSize));

    GenerateVertices(vertices, nSize);

    GenerateArestas(vertices, arestas, nSize, kSize);

    int startVertice = rand() % (nSize);

    // Garante um vértice final diferente
    int endVertice;
    do {
        endVertice = rand() % (nSize);
    } while (endVertice == startVertice);

    // ----------------------------------------------------------------------------

    PathFinderFactory factory = PathFinderFactory();
    IPathFinder *test = factory.Astar();

    test->FindPath(vertices, arestas);

    delete test;
    return 0;
}

void GenerateVertices(std::vector<std::tuple<int, int>> &vertices, int nSize) {
    for (int i = 0; i < nSize; i++) {
        std::get<0>(vertices[i]) = rand() % (nSize + 1);
        std::get<1>(vertices[i]) = rand() % (nSize + 1);
    }
}

void GenerateArestas(std::vector<std::tuple<int, int>> &vertices,
                     std::vector<std::vector<Edge>> &arestas, int nSize,
                     int kSize) {
    for (int i = 0, x; i < nSize; i++) {
        for (int k = 0; k < kSize; k++) {

            int verticeConnection;
            do {
                verticeConnection = rand() % (nSize);
            } while (verticeConnection == i);

            double distance =
                GetDistance(vertices[i], vertices[verticeConnection]);

            arestas[i][k] = Edge(verticeConnection, distance);
        }
    }
}

double GetDistance(std::tuple<int, int> x, std::tuple<int, int> y) {
    double temp = pow(get<0>(x) - get<0>(y), 2) + pow(get<1>(x) - get<1>(y), 2);
    return sqrt(temp);
}