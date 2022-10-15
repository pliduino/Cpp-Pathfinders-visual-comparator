#include "PathFinder/PathFinderDijkstra.h"
#include "Graph/Node.h"

#include <fstream>
#include <iostream>
#include <queue>

std::vector<Node> *PathFinderDijkstra::FindPath(Graph graph, int startVertice,
                                                int endVertice) {
    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::queue<int> queue;

#ifdef LOGSTEP
    std::fstream fs;
    fs.open("steplog/step.log", std::fstream::out);
    fs << "Dijkstra " << graph.nSize << " " << graph.kSize << std::endl;
#endif
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
#ifdef LOGSTEP
    fs << startVertice << " 1" << std::endl;
    fs << endVertice << " 4" << std::endl;
    fs << "#" << std::endl;
#endif

    //------------------------

    while (true) {
        steps++;
        int curNode = queue.front();
        queue.pop();
#ifdef LOGSTEP
        // VisitingState
        fs << curNode << " 2" << std::endl;
#endif

        for (auto const &[nextIndex, value] : graph.arestas[curNode]) {
            if ((*nodes)[curNode].weight + value < (*nodes)[nextIndex].weight) {
                (*nodes)[nextIndex].path = &(*nodes)[curNode];
                (*nodes)[nextIndex].weight = (*nodes)[curNode].weight + value;
                queue.push(nextIndex);
#ifdef LOGSTEP
                // ToVisitState
                fs << nextIndex << " 1" << std::endl;
#endif
            }
        }
#ifdef LOGSTEP
        fs << "#" << std::endl;

        fs << curNode << " 3" << std::endl;
#endif
        if (queue.empty()) {
#ifdef LOGSTEP
            fs << endVertice << " 5" << std::endl;
#endif
            std::cout << "Dijkstra Steps: " << ++steps << std::endl;
            return nodes;
        }
    }
}