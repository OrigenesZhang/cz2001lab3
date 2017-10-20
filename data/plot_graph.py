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
    for fileName in os.listdir(os.getcwd()):
        if re.match(r'(insertion|mergesort)\_(a|d|r)\.out', fileName):
            with open(fileName) as f:
                content = [line.split() for line in f.read().strip().split('\n')]
            fileName = fileName[:fileName.find('.')]
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