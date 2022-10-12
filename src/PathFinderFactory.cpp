#include "PathFinderFactory.h"
#include "PathFinder/PathFinderAstar.h"

IPathFinder *PathFinderFactory::Astar() { return new PathFinderAstar(); }