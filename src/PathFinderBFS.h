#include "IPathFinder.h"
#include <queue>

#pragma once

class PathFinderBFS : public IPathFinder {
  public:
    Node *FindPath(Graph graph, int startVertice, int endVertice) override;

  private:
    Node *Pop(Graph graph, std::queue<Node> &queue, int endVertice,
              bool visited[]);
};