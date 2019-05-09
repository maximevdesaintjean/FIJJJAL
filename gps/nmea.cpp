#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "nmea.h"
#include "struct.h"

using namespace std;

NMEA::NMEA() {

}

void NMEA::parseGPGGA(char *nmea, gpgga_t *loc)
{
    char *p = nmea;

    p = strchr(p, ',')+1; //skip time

    p = strchr(p, ',')+1;
    loc->latitude = atof(p);

    p = strchr(p, ',')+1;
    switch (p[0]) {
        case 'N':
            loc->lat = 'N';
            break;
        case 'S':
            loc->lat = 'S';
            break;
        case ',':
            loc->lat = '\0';
            break;
    }

    p = strchr(p, ',')+1;
    loc->longitude = atof(p);

    p = strchr(p, ',')+1;
    switch (p[0]) {
        case 'W':
            loc->lon = 'W';
            break;
        case 'E':
            loc->lon = 'E';
            break;
        case ',':
            loc->lon = '\0';
            break;
    }

    p = strchr(p, ',')+1;
    loc->quality = (int)atoi(p);

    p = strchr(p, ',')+1;
    loc->satellites = (int)atoi(p);

    p = strchr(p, ',')+1;

    p = strchr(p, ',')+1;
    loc->altitude = atof(p);
}

void NMEA::parseGPRMC(char *nmea, gprmc_t *loc)
{
    char *p = nmea;

    p = strchr(p, ',')+1; //skip time
    p = strchr(p, ',')+1; //skip status

    p = strchr(p, ',')+1;
    loc->latitude = atof(p);

    p = strchr(p, ',')+1;
    switch (p[0]) {
        case 'N':
            loc->lat = 'N';
            break;
        case 'S':
            loc->lat = 'S';
            break;
        case ',':
            loc->lat = '\0';
            break;
    }

    p = strchr(p, ',')+1;
    loc->longitude = atof(p);

    p = strchr(p, ',')+1;
    switch (p[0]) {
        case 'W':
            loc->lon = 'W';
            break;
        case 'E':
            loc->lon = 'E';
            break;
        case ',':
            loc->lon = '\0';
            break;
    }

    p = strchr(p, ',')+1;
    loc->speed = atof(p);

    p = strchr(p, ',')+1;
    loc->course = atof(p);
}

int NMEA::getMessageType(const char *message)
{
    if (strstr(message, "$GPGGA") != NULL) {
        return 1;
    }

    if (strstr(message, "$GPRMC") != NULL) {
        return 2;
    }

    return 0;
}