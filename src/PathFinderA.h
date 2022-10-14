#include "IPathFinder.h"

#pragma once

class PathFinderA : public IPathFinder {
  public:
    std::vector<Node> *FindPath(Graph graph, int startVertice,
                                int endVertice) override;
};