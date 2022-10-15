#include "PathFinder/PathFinderDFS.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <stdlib.h>

std::vector<Node> *PathFinderDFS::FindPath(Graph graph, int startVertice,
                                           int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::stack<Node *> stack;
#ifdef LOGSTEP
    std::fstream fs;
    fs.open("steplog/step.log", std::fstream::out);
    fs << "Alg: DFS NSize: " << graph.nSize << " KSize: " << graph.kSize
       << std::endl;
#endif

    bool visited[graph.nSize] = {false};

    visited[startVertice] = true;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;
    }
    (*nodes)[startVertice].weight = 0;

    stack.push((*nodes)[startVertice].SetValues(0, NULL));

#ifdef LOGSTEP
    fs << startVertice << " 1" << std::endl;
    fs << endVertice << " 4" << std::endl;
    fs << "#" << std::endl;
#endif

    //---------------

    while (true) {

        Node *curNode = stack.top();
        stack.pop();
#ifdef LOGSTEP
        fs << curNode->index << " 2" << std::endl;
#endif

        for (auto const &[nextIndex, value] : graph.arestas[curNode->index]) {

            if (visited[nextIndex]) {
                continue;
            }

            if (nextIndex == endVertice) {
#ifdef LOGSTEP
                fs << curNode->index << " 3" << std::endl;
                fs << nextIndex << " 5" << std::endl;
#endif

                (*nodes)[nextIndex].SetValues(curNode->weight + value, curNode);

                return nodes;
            }

            visited[nextIndex] = true;

            stack.push((*nodes)[nextIndex].SetValues(curNode->weight + value,
                                                     curNode));

#ifdef LOGSTEP
            fs << nextIndex << " 1" << std::endl;
#endif
        }

#ifdef LOGSTEP
        fs << "#" << std::endl;
        fs << curNode->index << " 3" << std::endl;
#endif

        if (stack.empty()) {
            return nodes;
        }
    }
}