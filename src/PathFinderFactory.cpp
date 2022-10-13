#include "PathFinderFactory.h"
#include <cstring>

IPathFinder *PathFinderFactory::Create(char *algorithm) {
    if (std::strcmp(algorithm, "A*") == 0)
        return new PathFinderAstar();
    if (std::strcmp(algorithm, "DFS") == 0)
        return new PathFinderDFS();
    if (std::strcmp(algorithm, "BFS") == 0)
        return new PathFinderBFS();
    if (std::strcmp(algorithm, "Dijkstra") == 0)
        return new PathFinderDijkstra();
    if (std::strcmp(algorithm, "BestFirst") == 0)
        return new PathFinderBestFirst();
    return NULL;
}