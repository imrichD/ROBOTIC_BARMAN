# ImportSerial.py
import serial

def send_signal_to_esp32(number):
    print(f"Sending {number} to ESP32")
    try:
        ser = serial.Serial('COM5', 115200, timeout=1)  # Update COM5 if needed
        print(ser.name)
        ser.write(str(number).encode())  # Send number as bytes
        ser.close()
    except Exception as e:
        print(f"Failed to send signal: {e}")
