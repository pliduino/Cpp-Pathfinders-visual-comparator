#include "IPathFinder.h"
#include "PathFinderAstar.h"
#include "PathFinderBFS.h"
#include "PathFinderDFS.h"

#pragma once

class PathFinderFactory {
  public:
    IPathFinder *Create(char *algorithm);
};