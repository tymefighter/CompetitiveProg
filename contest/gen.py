import numpy as np


fl = open('test', 'w')
t = 5000
fl.write(str(t) + "\n")

for i in range(t):

    n = np.random.randint(1, 30)
    fl.write(str(n) + "\n")

    for j in range(2):
        for k in range(n):
            fl.write(str(np.random.randint(1, 7)))
        fl.write("\n")

fl.close()