#include "PathFinder/PathFinderFactory.h"

#include "PathFinder/PathFinderA.h"
#include "PathFinder/PathFinderAstar.h"
#include "PathFinder/PathFinderBFS.h"
#include "PathFinder/PathFinderBestFirst.h"
#include "PathFinder/PathFinderDFS.h"
#include "PathFinder/PathFinderDijkstra.h"
#include <string>

IPathFinder *PathFinderFactory::Create(std::string algorithm) {
    if (algorithm == "A")
        return new PathFinderA();
    if (algorithm == "Astar")
        return new PathFinderAstar();
    if (algorithm == "DFS")
        return new PathFinderDFS();
    if (algorithm == "BFS")
        return new PathFinderBFS();
    if (algorithm == "Dijkstra")
        return new PathFinderDijkstra();
    if (algorithm == "BestFirst")
        return new PathFinderBestFirst();
    return NULL;
}