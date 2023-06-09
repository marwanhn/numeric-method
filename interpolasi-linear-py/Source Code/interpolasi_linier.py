# -*- coding: utf-8 -*-
"""Copy of Intepolasi Linear.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/15dMdHxT9To0IMrHrN6mzJ1FCm1-b48NA
"""

import matplotlib.pyplot as plt
from scipy import stats
# Kelompok 4 Interpolasi Linear

# Input section
# Reading first point
print('Enter first point:')
x0 = float(input('x0 = '))
y0 = float(input('y0 = '))

# Reading second point
print('Enter second point:')
x1 = float(input('x1 = '))
y1 = float(input('y1 = '))

# Reading calculation point
xp = float(input('Enter calculation point xp: '))

# Calculating interpolated value
yp = y0 + ((y1-y0)/(x1-x0)) * (xp - x0)

# Displaying result
print('Interpolated value at %0.4f is %0.4f' %(xp,yp))

# Displaying Graph
x = [x0, x1]
y = [y0, y1]

plt.plot(x, y)
plt.scatter(x, y, color='red')
plt.scatter(xp, yp, color='black', marker='x')