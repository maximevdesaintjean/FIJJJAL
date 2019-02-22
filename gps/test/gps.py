import serial 
import pynmea2


class GPS():
    def __init__(self, uart):
        self.lat = 0
        self.lng = 0
        self.__uart = uart

    def run(self):
        while(True):
            while(uart.inWaiting() == 0):
                pass
            
            try:
                line = uart.readline()
                msg = pynmea2.parse(line)
                if isinstance(msg, pynmea2.types.GGA):
                    if not hasattr(msg, 'longitude') or not hasattr(msg, 'latitude'):
                        print("no signal")
                        continue
                self.lat = msg.latitude
                self.lng = msg.longitude
                print(self.lat)
                print(self.lng)
                
            except Exception as e:
                print(e)
                
            
uart = serial.Serial(port='/dev/ttyO1', baudrate=9600)
gps = GPS(uart)
gps.run()
