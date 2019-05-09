#ifndef GPS_H
#define GPS_H

#include "serial.h"
#include "nmea.h"
#include "struct.h"

using namespace std;

class Gps
{
    public:
        Gps();

        void gpsInit(void);
        void gpsLocation(loc_t *);
        void gpsClose(void);

    private:
        Serial serial;
        NMEA nmea;

        void gpsConvert(double *, char, double *, char);
        double gpsDegDec(double);
};
#endif
