#include <stdio.h>

#pragma once

class IPathFinder {
public:
  virtual ~IPathFinder(){};
  virtual void FindPath() = NULL;
};