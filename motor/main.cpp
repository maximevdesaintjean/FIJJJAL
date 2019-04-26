#include <iostream>
#include <fstream>
#include <unistd.h>
#include <pigpio.h>

#include "motor.h"
void Calibration();
Motor mot1 = Motor(22);
Motor mot2 = Motor(18);

using namespace std;

int main() {
	
	if (gpioInitialise() < 0)
    {
		fprintf(stderr, "pigpio initialisation failed\n");
		return 1;
    }
	//Motor mot1 = Motor(17);
	//Motor mot2 = Motor(27);
	
	char x;
	
	mot1.initialize();
	mot2.initialize();
	
	x = getchar();
	while (x != 'q'){
		if (x == 'c'){
			Calibration();
		}
		else{	
			cout << "Démarrage";
			mot1.setPWM(1700);
			mot2.setPWM(1700);
			sleep(1);
			mot1.setPWM(0);
			mot2.setPWM(0);
		}
		x = getchar();
	}

    mot1.stop();
    mot2.stop();
	
    return 0;
}

void Calibration(){
   char y;

   mot1.setPWM(2000);
   mot2.setPWM(2000);
   //gpioServo(22, 2000);
   printf("Connect the battery !, wait music\n");
   y = getchar();
   
   if (y != 'q')
   {
      getchar();
      mot1.setPWM(1000);
      mot2.setPWM(1000);
      //gpioServo(22, 1000);
      printf("Servo Pulse on Min\n");
      sleep(6);
      printf("Done Calibrating, REMOVE THE BATTERY THEN PUT IT BACK\n");
      getchar();
   }
}
