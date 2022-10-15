#include "PathFinder/IPathFinder.h"

#pragma once

class PathFinderDijkstra : public IPathFinder {
  public:
    std::vector<Node> *FindPath(Graph graph, int startVertice,
                                int endVertice) override;
};