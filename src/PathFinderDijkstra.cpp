#include "PathFinderDijkstra.h"
#include "Node.h"
#include <iostream>
#include <queue>

std::vector<Node> *PathFinderDijkstra::FindPath(Graph graph, int startVertice,
                                                int endVertice) {
    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::queue<int> queue;
    int steps;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;

        if (i == startVertice)
            (*nodes)[i].weight = 0;
        else
            (*nodes)[i].weight = INFINITY;
    }

    queue.push(startVertice);

    //------------------------

    while (true) {
        steps++;
        int curNode = queue.front();
        queue.pop();

        for (auto const &[nextIndex, value] : graph.arestas[curNode]) {
            if ((*nodes)[curNode].weight + value < (*nodes)[nextIndex].weight) {
                (*nodes)[nextIndex].path = &(*nodes)[curNode];
                (*nodes)[nextIndex].weight = (*nodes)[curNode].weight + value;
                queue.push(nextIndex);
            }
        }

        if (queue.empty()) {
            std::cout << "Dijkstra Steps: " << ++steps << std::endl;
            return nodes;
        }
    }
}