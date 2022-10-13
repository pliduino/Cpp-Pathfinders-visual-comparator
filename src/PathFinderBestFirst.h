#include "IPathFinder.h"
#include <queue>

#pragma once

class PathFinderBestFirst : public IPathFinder {
  public:
    Node *FindPath(Graph graph, int startVertice, int endVertice) override;
};