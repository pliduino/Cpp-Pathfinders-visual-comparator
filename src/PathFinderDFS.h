#include "IPathFinder.h"
#include <stack>

#pragma once

class PathFinderDFS : public IPathFinder {
  public:
    Node *FindPath(Graph graph, int startVertice, int endVertice) override;

  private:
    Node *Pop(Graph graph, std::stack<Node *> &stack, int endVertice,
              bool visited[]);
};