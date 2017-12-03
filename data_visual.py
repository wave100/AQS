import csv
from pylab import *

data = []
data2 = [] 
data3 = []
data4 = []
timer = []
with open('DATALOG.csv', 'r') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        temp = int(row[0])
        timeTemp = int(row[0])
        dtemp = int(row[1])
        dtemp2 = int(row[2])
        dtemp3 = int(row[3])
        dtemp4 = int(row[4])
        timer.append(timeTemp)
        data.append(dtemp)
        data2.append(dtemp2)
        data3.append(dtemp3)
        data4.append(dtemp4)
        
plot(timer, data)
plot(timer, data2)
plot(timer, data3)
plot(timer, data4)

xlabel('time (milliseconds)')
ylabel('parts per million (ppm)')
title('Concentration of Gas')
grid(True)
show()