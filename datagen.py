import random

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

START_LAT = 42.734263
START_LON = -73.582003

DELTA = 0.000001

DATA_LEN = 50

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

XARR = []
YARR = []
ZARR = []

PREV_PPM = 750

#OUT_FILENAME = "data.csv"
#OUT_FILE = open(OUT_FILENAME, "w")

for i in range(DATA_LEN):
    for j in range(DATA_LEN):
        NEW_LAT = START_LAT + (i * DELTA)
        NEW_LON = START_LON + (j * DELTA)
        PPM1 = min(PREV_PPM + random.randint(-100, 100), 1000)

        XARR.append(NEW_LAT)
        YARR.append(NEW_LON)
        ZARR.append(PPM1)
#        PPM2 = random.randint(10, 1000)
#        PPM3 = random.randint(10, 1000)
#        PPM4 = random.randint(10, 1000)
#        PPM5 = random.randint(10, 1000)
#        PPM6 = random.randint(10, 1000)
#        OUT_FILE.write(str(NEW_LAT) + "," + str(NEW_LON) + "," + str(PPM1) + "," + str(PPM2) + "," + str(PPM3) + "," + str(PPM4) + "," + str(PPM5) + "," + str(PPM6) + "\n")
ax.scatter(XARR, YARR, ZARR, c='r', marker='^')
ax.set_zlim(0, 1000)
plt.show()
