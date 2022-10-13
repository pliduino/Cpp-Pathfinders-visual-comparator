#include "PathFinderBFS.h"

#include <iostream>
#include <queue>
#include <stdlib.h>

Node *PathFinderBFS::FindPath(Graph graph, int startVertice, int endVertice) {
    std::queue<Node> queue;
    bool visited[graph.nSize];
    queue.push(Node(startVertice, 0));

    return Pop(graph, queue, endVertice, visited);
}

Node *PathFinderBFS::Pop(Graph graph, std::queue<Node> &queue, int endVertice,
                         bool visited[]) {
    // while (true) {

    //     Node curNode = queue.front();
    //     queue.pop();

    //     for (auto const &[nextIndex, value] : graph.arestas[curNode.index]) {
    //         Node(nextIndex, curNode.weight + value, curNode.path);

    //         if (nextIndex == endVertice) {
    //             curNode.weight += value;
    //             (*curNode.path.push_back(nextIndex);
    //             return curNode;
    //         }

    //         if (visited[nextIndex]) {
    //             continue;
    //         }

    //         visited[nextIndex] = true;
    //         queue.push(Node(nextIndex, curNode.weight + value,
    //         curNode.path));
    //     }

    //     if (queue.empty()) {
    return new Node();
    //     }
    // }
}