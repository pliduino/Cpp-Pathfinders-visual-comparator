# 0-Not Visited 1-ToVisit 2-Visiting 3-Visited 4-End
import time
import proce

n_states = 50
screen_size = 400
step_size = 400/n_states

fStep = open("D:\GitHub\IA-Trabalho1\steplog\Astarstep.log", "r")
fVertex = open("D:\GitHub\IA-Trabalho1\steplog\vertices.log", "r")
fEdge = open("D:\GitHub\IA-Trabalho1\steplog\arestas.log", "r")


positions = [{0, 0} for i in range(n_states)]
states = [0 for i in range(n_states)]


def setup():
    size(400, 400)
    for line, position in fVertex, positions:
        splitted_line = line.split()
        position = {splitted_line[0], splitted_line[1]}


def draw():
    for line in fStep:
        splitted_line = line.split()
        if splitted_line[0] == "#":
            update()
            time.sleep(1)
            continue
        states[splitted_line[0]] = splitted_line[1]
        time.sleep(0.2)


def update():
    clear()
    background(255)

    for state, position in states, positions:
        if state == 0:
            fill(120, 120, 120)
        elif state == 1:
            fill(255, 102, 0)
        elif state == 2:
            fill(0, 200, 0)
        elif state == 3:
            fill(0, 0, 0)
        elif state == 4:
            fill(255, 0, 0)
        circle(position[0], position[1], 20)
