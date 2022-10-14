#include "PathFinder/PathFinderAstar.h"
#include "Utils.h"

#include <iostream>
#include <set>
#include <stack>

std::vector<Node> *PathFinderAstar::FindPath(Graph graph, int startVertice,
                                             int endVertice) {

    std::vector<Node> *nodes = new std::vector<Node>(graph.nSize, Node());
    std::stack<int> stack;

    std::map<double, int> map;

    int steps = 0;

    for (int i = 0; i < graph.nSize; i++) {
        (*nodes)[i].path = NULL;
        (*nodes)[i].index = i;

        if (i == startVertice)
            (*nodes)[i].weight = 0;
        else
            (*nodes)[i].weight = INFINITY;
    }

    map.insert(std::pair(
        GetDistance(graph.vertices[startVertice], graph.vertices[endVertice]) +
            (*nodes)[startVertice].weight,
        startVertice));

    //------------------------
    while (true) {
        steps++;

        auto i = map.begin();

        int curNode = (*i).second;
        map.erase(i);

        if (curNode == endVertice) {
            std::cout << "A* Steps: " << steps << std::endl;
            return nodes;
        }

        for (auto const &[nextIndex, value] : graph.arestas[curNode]) {
            if ((*nodes)[curNode].weight + value < (*nodes)[nextIndex].weight) {
                (*nodes)[nextIndex].path = &(*nodes)[curNode];
                (*nodes)[nextIndex].weight = (*nodes)[curNode].weight + value;
                map.insert(std::pair(GetDistance(graph.vertices[nextIndex],
                                                 graph.vertices[endVertice]) +
                                         (*nodes)[nextIndex].weight,
                                     nextIndex));
            }
        }

        if (map.empty()) {
            std::cout << "A* Steps: " << steps << std::endl;
            return nodes;
        }
    }
}