#ifndef NMEA_H
#define NMEA_H

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

using namespace std;

class NMEA {
    public:
        NMEA();

        int getMessageType(const char *);
        void parseGPGGA(char *, gpgga_t *);
        void parseGPRMC(char *, gprmc_t *);  
}; 
#endif

