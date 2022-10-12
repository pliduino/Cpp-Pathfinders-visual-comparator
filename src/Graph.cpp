#include "Graph.h"
#include <stdlib.h>
#include <time.h>

Graph::Graph(int nSize, int nEdges) {
    srand(time(NULL));
    int x = rand() % (nSize + 1);
}