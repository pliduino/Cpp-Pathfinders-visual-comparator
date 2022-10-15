#include "PathFinder/PathFinderBFS.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <stdlib.h>

std::vector<Node> *PathFinderBFS::FindPath(Graph graph, int startVertice,
                                           int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::queue<Node *> queue;
#ifdef LOGSTEP
    std::fstream fs;
    fs.open("steplog/step.log", std::fstream::out);
#endif

    bool visited[graph.nSize] = {false};

    visited[startVertice] = true;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;
    }
    (*nodes)[startVertice].weight = 0;

    queue.push((*nodes)[startVertice].SetValues(0, NULL));

#ifdef LOGSTEP
    fs << startVertice << " 1" << std::endl;
    fs << endVertice << " 4" << std::endl;
    fs << "#" << std::endl;
#endif

    //---------------

    while (true) {

        Node *curNode = queue.front();
        queue.pop();
#ifdef LOGSTEP
        fs << curNode->index << " 2" << std::endl;
#endif

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {

            if (visited[nextIndex]) {
                continue;
            }

            if (nextIndex == endVertice) {
#ifdef LOGSTEP
                fs << nextIndex << " 5" << std::endl;
#endif
                (*nodes)[nextIndex].SetValues(curNode->weight + value, curNode);

                return nodes;
            }

            visited[nextIndex] = true;

            queue.push((*nodes)[nextIndex].SetValues(curNode->weight + value,
                                                     curNode));

#ifdef LOGSTEP
            fs << nextIndex << " 1" << std::endl;
#endif
        }
#ifdef LOGSTEP
        fs << "#" << std::endl;
        fs << curNode->index << " 3" << std::endl;
#endif

        if (queue.empty()) {
            return nodes;
        }
    }
}