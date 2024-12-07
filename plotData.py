import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

arduino = serial.Serial("COM5", 9600) # adjust COM and baudrate
xData, yData = [], []
limitData = 30

def update(_):
    try:
        readValue = float(arduino.readline().decode().strip())
        yData.append(readValue)
        xData.append(len(xData))
        
        xData[:], yData[:] = xData[-limitData:], yData[-limitData:]
        
        ax.clear()
        ax.plot(xData, yData)
        ax.set_title("Real-time Arduino data")
        ax.set_xlabel("Time")
        ax.set_ylabel("Value")
        ax.grid(True)
    except ValueError:
        pass

fig, ax = plt.subplots()
ani = FuncAnimation(fig, update, interval=500)
plt.show()
