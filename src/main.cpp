#include "PathFinderFactory.h"

#include <iostream>

int main(int argc, char *argv[]) {
  PathFinderFactory factory = PathFinderFactory();
  IPathFinder *test = factory.Astar();

  test->FindPath();

  delete test;
  return 0;
}