#include "IPathFinder.h"

#pragma once

class PathFinderAstar : public IPathFinder {
  public:
    Node *FindPath(Graph graph, int startVertice, int endVertice) override;
};