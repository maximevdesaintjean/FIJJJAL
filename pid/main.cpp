#include <iostream>
#include <fstream>

using namespace std;

#include "pid.h"

int main() {
    PID pid = PID();
    float value = 25;
    float setPoint = 0.0;

    ofstream fichier("../log.txt", ios::out);

    if(fichier) { 
        while (value >= 0.01 || value <= -0.01) {
            fichier << pid.calcPID(setPoint, value) << endl;

            value = 0.0;
        }

        fichier.close();
    }
    else {
        cout << "Error open file: log.txt"<< endl;
    }

    return 0;
}