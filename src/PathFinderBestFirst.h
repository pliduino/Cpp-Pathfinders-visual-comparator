#include "IPathFinder.h"
#include <queue>

#pragma once

class PathFinderBestFirst : public IPathFinder {
  public:
    std::vector<Node> *FindPath(Graph graph, int startVertice,
                                int endVertice) override;
};