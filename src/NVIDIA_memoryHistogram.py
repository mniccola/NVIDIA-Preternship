import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib import colors
import numpy as np

# Read file
suggest_file = open('../suggest.txt')

# store suggest.txt values in list
stats = []
iter = 0
for row in suggest_file:
    if iter < 7:
        stats.append(row.split(': ', 1)[1])
        stats[iter] = float(stats[iter])
        iter = iter + 1
    else:
        d_file = row.split(': ', 1)[1]


newfile = open(d_file)

# store all memory values in list
memories = []
memories_array = []
i = 0
for line in newfile:
    memories.append(line.split(','))
    memories[i][0] = float(memories[i][0])
    memories_array.append(memories[i][0])
    i = i + 1

fig, axs = plt.subplots(1, 1, figsize = (10, 8), tight_layout = False)

# set number of bins
num_bins = stats[6] / 5
num_bins = int(num_bins)

# plot histogram 
plt.hist(memories_array, bins = num_bins, edgecolor = 'black')

plt.title('Job Memory Histogram')
plt.xlabel('Memory Allocated (GB)')
plt.ylabel('Frequency')
plt.savefig('../statistical_analysis.png')
plt.show()
