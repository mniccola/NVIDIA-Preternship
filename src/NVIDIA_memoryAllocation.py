
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np

# read file
newfile = open('suggest.txt')

# store suggest.txt values in a list
stats = []
i = 0
for line in newfile:
    if i < 7:
        stats.append(line.split(': ', 1)[1])
    
        stats[i] = float(stats[i])
        i = i + 1

# calculate mean +- standard deviation
m_plus_stdev = stats[1] + stats[3]
m_minus_stdev = stats[1] - stats[3]

ax = plt.gca()
ax.axes.xaxis.set_visible(False)

plt.ylabel("Memory Allocated (GB)")
plt.title('Statistical Analysis Results')

# plot horizontal lines
plt.axhline(y = stats[1], color = 'b', linestyle = '-')
plt.axhline(y = stats[2], color = 'r', linestyle = '-')
plt.axhline(y = m_plus_stdev, color = 'g', linestyle = '-')
plt.axhline(y = m_minus_stdev, color = 'g', linestyle = '-')
plt.axhline(y = stats[5], color = 'c', linestyle = '-')
plt.axhline(y = stats[6], color = 'y', linestyle = '-')
plt.axhline(y = stats[0], color = 'm', linestyle = '-')

# create legend
sugg_line = mpatches.Patch(color = 'm', label = 'Suggestion')
mean_line = mpatches.Patch(color = 'b', label = 'Mean')
median_line = mpatches.Patch(color = 'r', label = 'Median')
stdev_line = mpatches.Patch(color = 'g', label = 'Standard Deviations')
min_line = mpatches.Patch(color = 'c', label = 'Minimum')
max_line = mpatches.Patch(color = 'y', label = 'Maximum')

plt.legend(handles = [sugg_line, mean_line, median_line, stdev_line, min_line, max_line], bbox_to_anchor = (1.05, 1), fontsize = 8)
plt.tight_layout()

plt.savefig('statistical_analysis.png')
plt.show()