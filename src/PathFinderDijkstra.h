#include "IPathFinder.h"
#include <stack>

#pragma once

class PathFinderDijkstra : public IPathFinder {
  public:
    Node *FindPath(Graph graph, int startVertice, int endVertice) override;
};