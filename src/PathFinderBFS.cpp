#include "PathFinderBFS.h"

#include <iostream>
#include <queue>
#include <stdlib.h>

std::vector<Node> *PathFinderBFS::FindPath(Graph graph, int startVertice,
                                           int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::queue<Node *> queue;

    bool visited[graph.nSize] = {false};

    visited[startVertice] = true;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;
    }
    (*nodes)[startVertice].weight = 0;

    queue.push((*nodes)[startVertice].SetValues(0, NULL));

    //---------------

    while (true) {

        Node *curNode = queue.front();
        queue.pop();

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {

            if (visited[nextIndex]) {
                continue;
            }

            if (nextIndex == endVertice) {
                (*nodes)[nextIndex].SetValues(curNode->weight + value, curNode);

                return nodes;
            }

            visited[nextIndex] = true;

            queue.push((*nodes)[nextIndex].SetValues(curNode->weight + value,
                                                     curNode));
        }

        if (queue.empty()) {
            return nodes;
        }
    }
}