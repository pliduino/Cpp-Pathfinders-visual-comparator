#include "PathFinderDFS.h"

#include <iostream>
#include <stack>
#include <stdlib.h>

Node *PathFinderDFS::FindPath(Graph graph, int startVertice, int endVertice) {
    std::stack<Node *> stack;
    bool visited[graph.nSize] = {false};
    stack.push(new Node(startVertice, 0));
    visited[startVertice] = true;

    return Pop(graph, stack, endVertice, visited);
}

Node *PathFinderDFS::Pop(Graph graph, std::stack<Node *> &stack, int endVertice,
                         bool visited[]) {
    while (true) {

        Node *curNode = stack.top();
        stack.pop();

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {

            if (visited[nextIndex]) {
                continue;
            }

            if (nextIndex == endVertice) {
                Node *endNode =
                    new Node(nextIndex, curNode->weight + value, curNode);
                return endNode;
            }

            stack.push(new Node(nextIndex, curNode->weight + value, curNode));
        }

        visited[curNode->index] = true;
        if (stack.empty()) {
            return new Node();
        }
    }
}