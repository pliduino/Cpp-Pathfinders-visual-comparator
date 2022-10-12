#include "IPathFinder.h"

#pragma once

class PathFinderAstar : public IPathFinder {
public:
  virtual void FindPath();
};