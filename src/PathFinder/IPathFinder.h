#include <Edge.h>
#include <vector>

#pragma once

class IPathFinder {
  public:
    virtual ~IPathFinder(){};
    virtual void FindPath(std::vector<std::tuple<int, int>> vertices,
                          std::vector<std::vector<Edge>> arestas) = 0;
};