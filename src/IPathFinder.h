#include "Graph.h"
#include "Node.h"

#pragma once

class IPathFinder {
  public:
    virtual ~IPathFinder(){};
    virtual Node *FindPath(Graph graph, int startVertice, int endVertice) = 0;
};