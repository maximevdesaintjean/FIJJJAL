#include <iostream>
#include <fstream>

#include "motor.h"

using namespace std;

int main() {
    Motor mot = Motor(17);
    
    mot.initialize();
    mot.start();
    mot.setPWM(10);
    mot.stop();

    return 0;
}