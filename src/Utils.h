#include "Node.h"
#include <cmath>
#include <string>
#include <tuple>

double GetDistance(std::pair<int, int> verticeA, std::pair<int, int> verticeB);

std::pair<double, std::string *> GetPathDistance(Node *endNode);