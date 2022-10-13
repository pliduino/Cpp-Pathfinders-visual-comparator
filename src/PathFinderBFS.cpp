#include "PathFinderBFS.h"

#include <iostream>
#include <queue>
#include <stdlib.h>

Node *PathFinderBFS::FindPath(Graph graph, int startVertice, int endVertice) {
    std::queue<Node *> queue;
    bool visited[graph.nSize];
    queue.push(new Node(startVertice, 0, NULL));

    return Pop(graph, queue, endVertice, visited);
}

Node *PathFinderBFS::Pop(Graph graph, std::queue<Node *> &queue, int endVertice,
                         bool visited[]) {
    while (true) {
        if (queue.empty()) {
            return new Node();
        }

        Node *curNode = queue.front();
        queue.pop();

        if (visited[curNode->index]) {
            continue;
        }
        visited[curNode->index] = true;

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {

            if (nextIndex == endVertice) {
                return new Node(nextIndex, curNode->weight + value, curNode);
            }

            queue.push(new Node(nextIndex, curNode->weight + value, curNode));
        }
    }
}