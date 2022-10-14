#include "IPathFinder.h"

#pragma once

class PathFinderFactory {
  public:
    IPathFinder *Create(std::string algorithm);
};