from genericpath import isfile
from plotly.subplots import make_subplots
import plotly.express as px
import pandas as pd
import os

dir = "log"


def load_file(file):
    fileData = {}
    for line in file:
        s = line.split()

        if(len(s) == 0):
            continue
        elif(s[0] == "Algorithm:"):
            fileData["algorithm"] = [s[1]]
        elif(s[0] == "nSize:"):
            fileData["nSize"] = [int(s[1])]
        elif(s[0] == "kSize:"):
            fileData["kSize"] = [int(s[1])]
        elif(s[0] == "nTests:"):
            fileData["nTests"] = [int(s[1])]
        elif(s[0] == "Mean" and s[1] == "Execution"):
            x = s[3].replace("ms", "")

            fileData["mean_exec"] = [float(x)]

    return fileData


df = pd.DataFrame()

for filename in os.listdir(dir):
    path = os.path.join(dir, filename)

    if os.path.isfile(path):
        s = path.split()
        print(s)
        if s[0] == "log\\5000,":
            f = open(path, "r")
            dft = pd.DataFrame(data=load_file(f))
            df = pd.concat([df, dft], ignore_index=True)

print(df)
bar = px.bar(df, x="kSize", y="mean_exec",
                   color='algorithm', barmode='group',
                   height=400)

df2 = pd.DataFrame()

for filename in os.listdir(dir):
    path = os.path.join(dir, filename)

    if os.path.isfile(path):
        if path.find("Astar") != -1 or path.find("Dijkstra") != -1:
            f = open(path, "r")
            dft = pd.DataFrame(data=load_file(f))
            df2 = pd.concat([df2, dft], ignore_index=True)

df2 = df2.sort_values(by="nSize", axis="index")

line = px.line(df2, x="nSize", y=("mean_exec"),
               color="algorithm", line_dash="kSize",
               height=1000, markers=True)

#fig = line
fig = bar

fig.show()
