#include "IPathFinder.h"

#pragma once

class PathFinderDFS : IPathFinder {
public:
  void FindPath() override;
};