#include "IPathFinder.h"
#include <stack>

#pragma once

class PathFinderDFS : public IPathFinder {
  public:
    std::vector<Node> *FindPath(Graph graph, int startVertice,
                                int endVertice) override;
};