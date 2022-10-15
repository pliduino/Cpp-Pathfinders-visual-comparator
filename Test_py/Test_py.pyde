# 0-Not Visited 1-ToVisit 2-Visiting 3-Visited 4-End
import time


screen_size = 1000
step_size = (screen_size)/n_states


fStep = open(r"D:\GitHub\IA-Trabalho1\steplog\step.log", "r")
fVertex = open(r"D:\GitHub\IA-Trabalho1\steplog\vertices.log", "r")
fEdge = open(r"D:\GitHub\IA-Trabalho1\steplog\arestas.log", "r")

n_states = len(fVertex.readlines())

positions = [None for i in range(n_states)]
edges = [None for i in range(n_states*3)]
states = [0 for i in range(n_states)]



def update():
    global states, positions
    clear()
    background(255)
    
    #for edge in edges:
    #    print(edge[0])
    #    
    #    line(positions[edge[0]][0], positions[edge[0]][1], positions[edge[1]][0],positions[edge[1]][1])
    
    
    for (state, position) in zip(states, positions):
        if state == 0:
            fill(120, 120, 120)
        elif state == 1:
            fill(255, 255, 100)
        elif state == 2:
            fill(0, 200, 0)
        elif state == 3:
            fill(0, 0, 0)
        elif state == 4:
            fill(255, 0, 0)
        else:
            fill(0, 0, 255)
        circle(position[0], position[1], 15)
    
    
        

def setup():
    global positions, states
    
    size(screen_size, screen_size)
    
    i = 0
    
    for (line) in fVertex:
        splitted_line = line.split()
        positions[i] = (int(splitted_line[0])*step_size, int(splitted_line[1])*step_size)
        i+=1
        
    i = 0
    
    for (line) in fEdge:
        splitted_line = line.split()
        edges[i] = (int(splitted_line[0]), int(splitted_line[1]))
        i+=1
    
    


def draw():
    global positions, states
    line = fStep.readline()
    
    splitted_line = line.split()
    if splitted_line[0] == "#":
        update()
        
    else:    
        states[int(splitted_line[0])] = int(splitted_line[1])
        update()
        
    time.sleep(0.1)
        

    
