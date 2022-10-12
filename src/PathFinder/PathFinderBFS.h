#include "IPathFinder.h"

#pragma once

class PathFinderBFS : public IPathFinder {
public:
  void FindPath() override;
};