#include "PathFinder/PathFinderBestFirst.h"

#include <iostream>
#include <queue>
#include <stdlib.h>

std::vector<Node> *PathFinderBestFirst::FindPath(Graph graph, int startVertice,
                                                 int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    bool visited[graph.nSize] = {false};
    int nextNode;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;
    }
    (*nodes)[startVertice].weight = 0;

    Node *curNode = &(*nodes)[startVertice];
    //------------------------

    while (true) {
        double minValue = INFINITY;
        nextNode = -1;
        visited[curNode->index] = true;

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {
            if (visited[nextIndex]) {
                continue;
            }

            if (value < minValue) {
                minValue = value;

                nextNode = nextIndex;
            }
        }

        // Backtracking
        if (nextNode == -1) {
            curNode = curNode->path;
            if (curNode == NULL) {
                return nodes;
            }
        } else {
            curNode = (*nodes)[nextNode].SetValues(curNode->weight + minValue,
                                                   curNode);
        }

        if (curNode->index == endVertice) {
            return nodes;
        }
    }
}
