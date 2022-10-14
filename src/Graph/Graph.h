#include "Utils.h"

#include <map>
#include <stdlib.h>
#include <tuple>
#include <vector>

#pragma once

class Graph {
  public:
    std::vector<std::pair<int, int>> vertices;
    std::vector<std::map<int, double>> arestas;
    int nSize, kSize;

    Graph(int _nSize, int _kSize);

  private:
    void GenerateArestas();

    void GenerateVertices();
};