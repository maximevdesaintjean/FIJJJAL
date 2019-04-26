all : drone.exe

CC = g++

drone.exe: main.o motor.o ultrasound.o pid.o
	$(CC) -o drone.exe main.o ./motor/motor.o ./ultrasound/ultrasound.o ./pid/pid.o -lpigpio -lpthread

main.o: main.cpp ./motor/motor.h ./ultrasound/ultrasound.h ./pid/pid.h
	$(CC) -o main.o -c main.cpp


#Motor
motor.o: ./motor/motor.cpp ./motor/motor.h
	$(CC) -o ./motor/motor.o -c ./motor/motor.cpp -lpigpio -lpthread


#Ultrasound
ultrasound.o: ./ultrasound/ultrasound.cpp ./ultrasound/ultrasound.h
	$(CC) -o ./ultrasound/ultrasound.o -c ./ultrasound/ultrasound.cpp -lpigpio -lpthread


#PID
pid.o: ./pid/pid.cpp ./pid/pid.h
	$(CC) -o ./pid/pid.o -c ./pid/pid.cpp


clean:
	rm *.o
	rm ./motor/*.o
	rm ./ultrasound/*.o
	rm ./pid/*.o