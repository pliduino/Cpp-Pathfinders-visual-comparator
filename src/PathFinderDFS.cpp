#include "PathFinderDFS.h"

#include <iostream>
#include <stack>
#include <stdlib.h>

Node *PathFinderDFS::FindPath(Graph graph, int startVertice, int endVertice) {
    std::stack<Node *> stack;
    bool visited[graph.nSize];
    stack.push(new Node(startVertice, 0));

    return Pop(graph, stack, endVertice, visited);
}

Node *PathFinderDFS::Pop(Graph graph, std::stack<Node *> &stack, int endVertice,
                         bool visited[]) {
    while (true) {

        Node *curNode = stack.top();
        stack.pop();

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {
            Node(nextIndex, curNode->weight + value, curNode->path);

            if (nextIndex == endVertice) {
                Node *endNode = new Node(nextIndex, value, curNode);
                return endNode;
            }

            if (visited[nextIndex]) {
                continue;
            }

            visited[nextIndex] = true;
            stack.push(new Node(nextIndex, value, curNode));
        }

        if (stack.empty()) {
            return new Node();
        }
    }
}