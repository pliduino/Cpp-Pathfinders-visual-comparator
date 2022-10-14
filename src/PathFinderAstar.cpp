#include "PathFinderAstar.h"
#include "Utils.h"

#include <queue>

std::vector<Node> *PathFinderAstar::FindPath(Graph graph, int startVertice,
                                             int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::queue<int> queue;

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

        int curNode = queue.front();
        queue.pop();

        if (curNode == endVertice)
            return nodes;

        for (auto const &[nextIndex, value] : graph.arestas[curNode]) {
            if ((*nodes)[curNode].weight + value < (*nodes)[nextIndex].weight) {
                (*nodes)[nextIndex].path = &(*nodes)[curNode];
                (*nodes)[nextIndex].weight = (*nodes)[curNode].weight + value;
                queue.push(nextIndex);
            }
        }

        if (queue.empty())
            return nodes;
    }
}