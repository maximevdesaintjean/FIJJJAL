from pirc522 import RFID
import RPi.GPIO as GPIO
import subprocess
import os
import time

try:
    GPIO.cleanup()
except Exception as e:
    print(e)

rdr = RFID()
GPIO.setmode(GPIO.BOARD)

coord = False
magnet = 40
switch = 38

GPIO.setup(magnet, GPIO.OUT)
GPIO.setup(switch, GPIO.IN)

try:
    while True:
        while True:
            if GPIO.input(switch):
                # Wait for tag
                rdr.wait_for_tag()
                
                # Request tag
                (error, data) = rdr.request()
                
                if not error:
                    print("\nTag detected")
                    (error, uid) = rdr.anticoll()
                    if not error:
                        print("UID: " + str(uid))
                        # Select Tag is required before Auth
                        if not rdr.select_tag(uid):
                            # Auth for block 10 (block 2 of sector 2) using default shipping key A
                            if not rdr.card_auth(rdr.auth_a, 9, [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF], uid):
                                # This will print something like (False, [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
                                
                                # Read the entire block 10 (second argument is the informations)
                                informations = rdr.read(9)[1]
                                print(informations)

                                # Look for the sign of the latitude (N --> + / S --> -)
                                if (informations[0] == 0xFF):
                                    latitude = float("+{}.{}{}{}".format(int(informations[1]), int(informations[2]), int(informations[3]), int(informations[4])))
                                else : 
                                    latitude = float("-{}.{}{}{}".format(int(informations[1]), int(informations[2]), int(informations[3]), int(informations[4])))

                                # Look for the sign of the longitude (E --> + / O --> -)
                                if (informations[5] == 0xFF):
                                    longitude = float("+{}.{}{}{}".format(int(informations[6]), int(informations[7]), int(informations[8]), int(informations[9])))
                                else : 
                                    longitude = float("-{}.{}{}{}".format(int(informations[6]), int(informations[7]), int(informations[8]), int(informations[9])))

                                coord = [latitude, longitude]
                                print(coord)

                                # Always stop crypto1 when done working
                                rdr.stop_crypto()

                                GPIO.output(magnet, GPIO.HIGH)
                                print("\nElectromagnet ON")

                                while(True):
                                    b = subprocess.call(["../ludovic/drone.exe", str(latitude), str(longitude)], shell = False)

                                    """ if (b.stdout == "Hello World! +12.12 +12.12"):
                                        print("HELLO") """
                                    break

                                break

        while True:
            rdr.wait_for_tag()
            (error, data) = rdr.request()
            
            if not error :
                print("\nTag detected")
                (error, uid2) = rdr.anticoll()
                if not error:
                    print("Card read UID: " + str(uid2))
                    if uid != uid2 :
                        if not rdr.select_tag(uid2):
                            if not rdr.card_auth(rdr.auth_a, 9, [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF], uid2): 
                                informations = rdr.read(9)[1]
                                uid_unlock = informations[:5]
                                print("Value UID card : " + str(uid_unlock))
                                if uid == uid_unlock:               
                                    GPIO.output(magnet, GPIO.LOW)
                                    print("\nElectromagnet OFF")
                                    break
                                else:
                                    print("\nAcces Denied")
                    else:
                        print("\nAcces Denied")

        # Calls GPIO cleanup
        time.sleep(5)

except KeyboardInterrupt:
    GPIO.cleanup()