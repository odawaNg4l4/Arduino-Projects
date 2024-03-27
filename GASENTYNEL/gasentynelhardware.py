import africastalking
import serial
import tkinter as tk

threshold_temperature = 22.0  # Convert to float
threshold_humidity = 35.0  # Convert to floatpip inst
threshold_ppm = 30

arduino = serial.Serial(port='COM8', baudrate=9600, timeout=.1)

# Initialize Africa's Talking
africastalking.initialize(
    username='gasentynel',
    api_key='fa9bedf59696a590c47e3ba7d66280c63fd7c75880ae1ef040fea4a8d743dad7'
)
sms = africastalking.SMS


def sending(message):
    # Set the numbers in international format
    recipients = ["+254748742605"]
    # Set your message
    try:
        # Send the message
        response = sms.send(message, recipients)
        print(response)
    except Exception as e:
        print(f'Houston, we have a problem: {e}')


def update_gui(data):
    humidity, temperature, ppm = map(float, data.split(','))
    humidity_entry.delete(0, tk.END)
    humidity_entry.insert(0, humidity)
    temperature_entry.delete(0, tk.END)
    temperature_entry.insert(0, temperature)
    ppm_entry.delete(0, tk.END)
    ppm_entry.insert(0, ppm)

    if temperature > threshold_temperature or humidity > threshold_humidity:
        sending("Hello, Humidity level high, Temperature Level high, Ethylene level high, Open Ventilators")


def read_serial():
    while True:
        data = arduino.readline().decode().strip()  # Decode bytes to string and remove whitespace
        if data:
            print(data)
            update_gui(data)


# GUI Setup
root = tk.Tk()
root.title("Sensor Data")
root.geometry("400x200")

sensor_frame = tk.Frame(root)
sensor_frame.pack(pady=10)

humidity_label = tk.Label(sensor_frame, text="Humidity:")
humidity_label.grid(row=0, column=0, padx=10)
humidity_entry = tk.Entry(sensor_frame)
humidity_entry.grid(row=0, column=1, padx=10)

temperature_label = tk.Label(sensor_frame, text="Temperature:")
temperature_label.grid(row=1, column=0, padx=10)
temperature_entry = tk.Entry(sensor_frame)
temperature_entry.grid(row=1, column=1, padx=10)

ppm_label = tk.Label(sensor_frame, text="Ethylene Concentration:")
ppm_label.grid(row=2, column=0, padx=10)
ppm_entry = tk.Entry(sensor_frame)
ppm_entry.grid(row=2, column=1, padx=10)

# Start reading serial data in a separate thread
import threading

serial_thread = threading.Thread(target=read_serial)
serial_thread.daemon = True
serial_thread.start()

root.mainloop()
