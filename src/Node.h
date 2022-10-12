#include "Edge.h"

#pragma once

class Node {
  public:
    int m_x, m_y;
    Edge edge[];

    Node(int x, int y);

    void AddEdge(Node node);
};