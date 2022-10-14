#include "PathFinderDFS.h"

#include <iostream>
#include <stack>
#include <stdlib.h>

std::vector<Node> *PathFinderDFS::FindPath(Graph graph, int startVertice,
                                           int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::stack<Node *> stack;
    bool visited[graph.nSize] = {false};

    visited[startVertice] = true;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;
    }
    (*nodes)[startVertice].weight = 0;

    stack.push((*nodes)[startVertice].SetValues(0, NULL));

    //---------------

    while (true) {

        Node *curNode = stack.top();
        stack.pop();

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {

            if (visited[nextIndex]) {
                continue;
            }

            if (nextIndex == endVertice) {
                (*nodes)[nextIndex].SetValues(curNode->weight + value, curNode);

                return nodes;
            }

            visited[nextIndex] = true;

            stack.push((*nodes)[nextIndex].SetValues(curNode->weight + value,
                                                     curNode));
        }

        if (stack.empty()) {
            return nodes;
        }
    }
}