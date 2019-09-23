import serial
import csv
from datetime import datetime

ser = serial.Serial('/dev/ttyACM0')
ser.flushInput()

columnas = ['lm35','dht11tmp','dht11hum']

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = (ser_bytes[0:len(ser_bytes)-2].decode("utf-8")).split(",")
        #decoded_bytes.append(datetime.now().strftime('%Y-%m-%d %H:%M:%S'))
        decoded_bytes.append(datetime.now().strftime('%Y-%m-%d-%H:%M:%S'))
        print(decoded_bytes)
        with open("tmp-hum-test.csv","a") as data_file:
            #writer = csv.writer(data_file, delimiter =",")
            writer = csv.writer(data_file)
            writer.writerow(decoded_bytes)
    except:
        print("Keyboard Interrupt")
        break
