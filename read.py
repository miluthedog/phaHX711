import serial

arduino = serial.Serial("COM5", 9600)

while True:
    try:
        data = arduino.readline().decode().strip()  # Read and decode
        number = float(data)  # Convert to a number (float or int)
        print(f"Number: {number}, Calculated: {number * 2}")  # Example calculation
    except ValueError:
        print(f"NaN: {data}")
