CXX = g++

CXXFLAGS	:= -std=c++17 -Wall -Wextra -g -D

OUTPUT	:= output

SRC		:= src

INCLUDE	:= include

LIB		:= lib

LOVE := love2d


MAIN	:= main
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p

INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%)) -I$(SRC)

LIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

OBJECTS		:= $(SOURCES:.cpp=.o)

OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))

all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!

run: all
	./$(OUTPUTMAIN) $(NSIZE) $(KSIZE) $(NTESTS) $(ALGORITHM)
	@echo Executing 'run: all' complete!

runall: all
	./$(OUTPUTMAIN) 5000 3 20 DFS BFS Dijkstra BestFirst Astar
	./$(OUTPUTMAIN) 5000 5 20 DFS BFS Dijkstra BestFirst Astar
	./$(OUTPUTMAIN) 5000 7 20 DFS BFS Dijkstra BestFirst Astar
	./$(OUTPUTMAIN) 5000 10 20 DFS BFS Dijkstra BestFirst Astar
	./$(OUTPUTMAIN) 5000 15 20 DFS BFS Dijkstra BestFirst Astar
	./$(OUTPUTMAIN) 5000 20 20 DFS BFS Dijkstra BestFirst Astar
	@echo Executing 'runall: all' complete!

runAD: all
	./$(OUTPUTMAIN) 5000 3 20 Dijkstra Astar
	./$(OUTPUTMAIN) 10000 3 20 Dijkstra Astar
	./$(OUTPUTMAIN) 15000 3 20 Dijkstra Astar
	./$(OUTPUTMAIN) 20000 3 20 Dijkstra Astar
	./$(OUTPUTMAIN) 50000 3 20 Dijkstra Astar
	./$(OUTPUTMAIN) 5000 5 20 Dijkstra Astar
	./$(OUTPUTMAIN) 10000 5 20 Dijkstra Astar
	./$(OUTPUTMAIN) 15000 5 20 Dijkstra Astar
	./$(OUTPUTMAIN) 20000 5 20 Dijkstra Astar
	./$(OUTPUTMAIN) 50000 5 20 Dijkstra Astar
	./$(OUTPUTMAIN) 5000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 10000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 15000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 20000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 50000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 5000 10 20 Dijkstra Astar
	./$(OUTPUTMAIN) 10000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 15000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 20000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 50000 7 20 Dijkstra Astar
	./$(OUTPUTMAIN) 5000 20 20 Dijkstra Astar
	./$(OUTPUTMAIN) 10000 20 20 Dijkstra Astar
	./$(OUTPUTMAIN) 15000 20 20 Dijkstra Astar
	./$(OUTPUTMAIN) 20000 20 20 Dijkstra Astar
	./$(OUTPUTMAIN) 50000 20 20 Dijkstra Astar
	@echo Executing 'runAD: all' complete!

love:
	love $(LOVE)