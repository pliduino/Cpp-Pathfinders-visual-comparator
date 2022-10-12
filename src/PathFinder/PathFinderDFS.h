#include "IPathFinder.h"

#pragma once

class PathFinderDFS : IPathFinder {
  public:
    void FindPath(std::vector<std::tuple<int, int>> vertices,
                  std::vector<std::vector<Edge>> arestas) override;
};