#include "PathFinderBestFirst.h"

#include <iostream>
#include <queue>
#include <stdlib.h>

Node *PathFinderBestFirst::FindPath(Graph graph, int startVertice,
                                    int endVertice) {

    Node *curNode = new Node(startVertice, 0, NULL);
    int nextNode;
    bool visited[graph.nSize];

    //------------------------

    while (true) {
        int minValue = INFINITY;
        nextNode = -1;

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
                return new Node();
            }

        } else {
            curNode = new Node(nextNode, curNode->weight + minValue, curNode);
            visited[nextNode] = true;
        }

        if (curNode->index == endVertice) {
            return curNode;
        }
    }
}
