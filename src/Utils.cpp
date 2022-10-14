#include "Utils.h"

#include <iomanip>
#include <iostream>

double GetDistance(std::pair<int, int> verticeA, std::pair<int, int> verticeB) {
    double temp = pow(verticeA.first - verticeB.first, 2) +
                  pow(verticeA.second - verticeB.second, 2);
    return sqrt(temp);
}

std::pair<double, std::string *> GetPathDistance(Node *endNode) {
    Node *parent = endNode;
    Node *child;
    double distance = endNode->weight;
    std::stringstream pathString;

    do {
        child = parent;
        parent = child->path;

        pathString << child->index << " <- ";

    } while (parent->path != NULL);

    pathString << parent->index;

    return {distance, new std::string(pathString.str())};
}