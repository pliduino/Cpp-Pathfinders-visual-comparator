#include "PathFinder/PathFinderBestFirst.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <stdlib.h>

std::vector<Node> *PathFinderBestFirst::FindPath(Graph graph, int startVertice,
                                                 int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());

#ifdef LOGSTEP
    std::fstream fs;
    fs.open("steplog/step.log", std::fstream::out);
    fs << "Alg: BestFirst NSize: " << graph.nSize << " KSize: " << graph.kSize
       << std::endl;
#endif

    bool visited[graph.nSize] = {false};
    int nextNode;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;
    }
    (*nodes)[startVertice].weight = 0;

    Node *curNode = &(*nodes)[startVertice];

#ifdef LOGSTEP
    fs << startVertice << " 1" << std::endl;
    fs << endVertice << " 4" << std::endl;
    fs << "#" << std::endl;
#endif
    //------------------------

    while (true) {
        double minValue = INFINITY;
        nextNode = -1;
        visited[curNode->index] = true;
#ifdef LOGSTEP
        fs << curNode->index << " 2" << std::endl;
#endif

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {
            if (visited[nextIndex]) {
                continue;
            }

            if (value < minValue) {
                minValue = value;

                nextNode = nextIndex;
            }
        }
#ifdef LOGSTEP
        fs << "#" << std::endl;
        fs << curNode->index << " 3" << std::endl;
#endif
        // Backtracking
        if (nextNode == -1) {
            curNode = curNode->path;
            if (curNode == NULL) {
                return nodes;
            }
        } else {
            curNode = (*nodes)[nextNode].SetValues(curNode->weight + minValue,
                                                   curNode);
        }

        if (curNode->index == endVertice) {
#ifdef LOGSTEP
            fs << endVertice << " 5" << std::endl;
#endif
            return nodes;
        }
    }
}
