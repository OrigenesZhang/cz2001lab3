import numpy as np
import matplotlib
matplotlib.use("AGG")
import matplotlib.pyplot as plt
import os
import re

def getTitle(fileName, type="CPU time"):
    pos = fileName.find('_')
    p = fileName[pos+1]
    return fileName[:pos].capitalize() + " Sort " + \
        {"r": "(Random)",
        "d": "(Descending)",
        "a": "(Ascending)",
        }.get(p) + "\n" + type

def main():
    x = np.arange(1000, 1000001, 10000)
    with open("insertion_d.out") as f:
        content = [line.split() for line in f.read().strip().split('\n')]
    fileName = "insertion_d"
    time = [item[0] for item in content]
    compare = [item[1] for item in content]
    plot(x, time, getTitle(fileName))
    plot(x, compare, getTitle(fileName, "num of cmp"), y_label="Number of comparison")

def plot(x, y, title, x_label="input data size", y_label="CPUtime"):
    plt.scatter(x, y)
    plt.title(title)
    plt.ylabel(y_label)
    plt.xlabel(x_label)
    plt.savefig(title.replace('\n', " "))
    plt.close()

if __name__ == "__main__":
    main()

