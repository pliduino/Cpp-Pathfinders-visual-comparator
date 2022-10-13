#include "Utils.h"

double GetDistance(std::pair<int, int> verticeA, std::pair<int, int> verticeB) {
    double temp = pow(verticeA.first - verticeB.first, 2) +
                  pow(verticeA.second - verticeB.second, 2);
    return sqrt(temp);
}