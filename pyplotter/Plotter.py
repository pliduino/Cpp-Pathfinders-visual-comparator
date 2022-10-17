import plotly.express as px
import pandas as pd
import os

DIR = "log"


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


def figures_to_html(figs):
    with open("pyplotter/plot.html", 'w') as dashboard:
        dashboard.write("<html><head></head><body>" + "\n")
        for fig in figs:
            inner_html = fig.to_html().split('<body>')[1].split('</body>')[0]
            dashboard.write(inner_html)
        dashboard.write("</body></html>" + "\n")


def plot_bar():
    df = pd.DataFrame()

    for filename in os.listdir(DIR):
        path = os.path.join(DIR, filename)

        if os.path.isfile(path):
            s = path.split()
            if s[0] == DIR + "\\5000,":
                f = open(path, "r")
                dft = pd.DataFrame(data=load_file(f))
                df = pd.concat([df, dft], ignore_index=True)

    df = df.sort_values(by="kSize", axis="index")

    return px.bar(df, x="kSize", y="mean_exec",
                  color='algorithm', barmode='group',
                  height=400)


def plot_line():

    df2 = pd.DataFrame()

    for filename in os.listdir(DIR):
        path = os.path.join(DIR, filename)

        if os.path.isfile(path):
            if path.find("Astar") != -1 or path.find("Dijkstra") != -1:
                f = open(path, "r")
                dft = pd.DataFrame(data=load_file(f))
                df2 = pd.concat([df2, dft], ignore_index=True)

    df2 = df2.sort_values(by="nSize", axis="index")
    print(df2)
    return px.line(df2, x="nSize", y="mean_exec",
                   color="algorithm", line_dash="kSize",
                   height=1000, markers=True)


bar = plot_bar()
line = plot_line()

figures_to_html([bar, line])
