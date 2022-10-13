#include "Edge.h"
#include "Graph.h"
#include "PathFinderFactory.h"

#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <tuple>
#include <vector>

double GetDistance(std::tuple<int, int> verticeA,
                   std::tuple<int, int> verticeB);

void TryPathFinder(Graph graph, int nTests, IPathFinder *pathFinder,
                   std::fstream &fs);

int main(int argc, char *argv[]) {
    std::fstream fs;
    std::stringstream ss;

    // Setting random seed
    srand(time(NULL));
    if (argc != 5) {
        std::cerr << "Wrong arguments";
        return -1;
    }

    // Getting variables
    int nSize = std::atoi(argv[1]);
    int kSize = std::atoi(argv[2]);
    int nTests = std::atoi(argv[3]);
    char *algorithmType = argv[4];

    ss << nSize << ", " << kSize << ", " << algorithmType;

    fs.open(ss.str(), std::fstream::out);

    Graph graph = Graph(nSize, kSize);

    // ----------------------------------------------------------------------------

    PathFinderFactory factory = PathFinderFactory();
    IPathFinder *pathFinder = factory.Create(algorithmType);

    fs << std::fixed;
    fs << std::setprecision(4);

    fs << "Algorithm: " << algorithmType << std::endl << std::endl;

    TryPathFinder(graph, nTests, pathFinder, fs);

    delete pathFinder;
    return 0;
}

void TryPathFinder(Graph graph, int nTests, IPathFinder *pathFinder,
                   std::fstream &fs) {
    int startVertice;
    int endVertice;
    double totalExecTime;
    double totalDist;
    int succesfulPaths = 0;

    for (int i = 0; i < nTests; i++) {
        startVertice = rand() % (graph.nSize);

        // Garante um vértice final diferente do inicial
        do {
            endVertice = rand() % (graph.nSize);
        } while (endVertice == startVertice);

        auto start = std::chrono::high_resolution_clock::now();

        Node *pathNode = pathFinder->FindPath(graph, startVertice, endVertice);

        auto end = std::chrono::high_resolution_clock::now();

        double execTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count();

        totalExecTime += execTime;

        fs << "Try number: " << i + 1 << std::endl;
        fs << "Start: " << startVertice << std::endl;
        fs << "Goal: " << endVertice << std::endl;

        if (pathNode->weight != -1) {
            std::pair<double, std::string *> values =
                Node::GetPathDistance(pathNode);

            double distance = values.first;
            std::string *pathString = values.second;

            fs << "Path: " << *pathString << std::endl;

            fs << "Distance: " << distance << std::endl;

            totalDist += distance;
            succesfulPaths++;
        } else {
            fs << "Path not found." << std::endl;
        }

        fs << "Execution Time: ";
        fs << execTime << "ms" << std::endl << std::endl;
    }

    fs << "Mean Distance: " << totalDist / (float)succesfulPaths << std::endl;
    fs << "Mean Execution Time: ";
    fs << totalExecTime / (float)nTests << "ms" << std::endl;
}