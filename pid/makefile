all : pid.exe

pid.exe: main.o pid.o
	g++ -o pid.exe main.o pid.o

pid.o: pid.cpp pid.h
	g++ -o pid.o -c pid.cpp

main.o: main.cpp pid.h
	g++ -o main.o -c main.cpp

clean:
	del *.o