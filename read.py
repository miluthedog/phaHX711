import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

arduino = serial.Serial("COM5", 9600) # adjust COM and baudrate
x_data, y_data = [], []

def update(_):
    try:
        raw_y = float(arduino.readline().decode().strip())
        y_data.append(raw_y)
        x_data.append(len(x_data))
        
        x_data[:], y_data[:] = x_data[-30:], y_data[-30:]
        
        ax.clear()
        ax.plot(x_data, y_data)
        ax.set_title("Real-Time Arduino data")
        ax.set_xlabel("Time")
        ax.set_ylabel("Value")
        ax.grid(True)
    except ValueError:
        pass

fig, ax = plt.subplots()
ani = FuncAnimation(fig, update, interval=500)
plt.show()
