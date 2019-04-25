#include <iostream>
#include <fstream>

using namespace std;

#include "pid.h"

int main() {
    PID pid = PID();
    float value = 10.0;
    float setPoint = 0.0;

    ofstream fichier("../log.txt", ios::out);

    if(fichier) { 
        while (value >= 0.01 || value <= -0.01) {
            fichier << value << endl;

            value += pid.calcPID(setPoint, value);            
        }

        fichier.close();
    }
    else {
        cout << "Error open file: log.txt"<< endl;
    }

    return 0;
}