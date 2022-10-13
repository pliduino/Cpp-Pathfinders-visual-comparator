#include "IPathFinder.h"
#include "PathFinderAstar.h"
#include "PathFinderBFS.h"
#include "PathFinderBestFirst.h"
#include "PathFinderDFS.h"
#include "PathFinderDijkstra.h"

#pragma once

class PathFinderFactory {
  public:
    IPathFinder *Create(char *algorithm);
};