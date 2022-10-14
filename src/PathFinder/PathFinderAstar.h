#include "PathFinder/IPathFinder.h"

#pragma once

class PathFinderAstar : public IPathFinder {
  public:
    std::vector<Node> *FindPath(Graph graph, int startVertice,
                                int endVertice) override;
};