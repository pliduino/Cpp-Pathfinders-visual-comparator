#include "IPathFinder.h"

#pragma once

class PathFinderAstar : public IPathFinder {
  public:
    void FindPath(std::vector<std::tuple<int, int>> vertices,
                  std::vector<std::vector<Edge>> arestas) override;
};