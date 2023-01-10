# Project Title

## Table of Contents

- [About](#about)
- [Usage](#usage)
  - [Execution](#execution)
  - [Visualization](#visualization)

## About
Project created using Love2d (Lua), python and C++ to visualize how different search algorithms work and how good they really are. The code can be extended to any search algorithm.

## Usage

- ### Execution

You need to set the following variables to execute the program a single time:

    - NSIZE — Number of nodes
    - KSIZE — Number of vertices
    - NTESTS — Number of tests
    - ALGORITHM — Algorithm used, they can be Astar, Djikstra, Bestfirst, BFS, DFS

You can set and execute them by running the following:

```make
    make run NSIZE=5000 KSIZE=3 NTESTS=20 ALGORITHM=Astar
```


You can also execute some default configurations to generate all the logs at the same time:

```make
    make runall
```

```make
    make runAD
```


---

- ### Visualization

By default you don't create the necessary logs for animations, to generate them simply add the flag LOGSTEP to the Makefile:

```make
    CXXFLAGS := -std=c++17 -Wall -Wextra -g -D LOGSTEP
```

Be careful as these logs are pretty expensive and mess up the output logs as the execution time gets significantly higher.

To read and animate previously created logs just run the following code:

```make
    make love
```
---

There's also a python script hardcoded to make a graph with runall and runAD logs using plotly, just run Plotter.py and open the generated plot.html file.