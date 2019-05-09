#ifndef STRUCT_H
#define STRUCT_H

using namespace std;

struct gpgga {
    double latitude;
    char lat;
    double longitude;
    char lon;
    int quality; //uint8_t
    int satellites; //uint8_t
    double altitude;
};
typedef struct gpgga gpgga_t;

struct gprmc {
    double latitude;
    char lat;
    double longitude;
    char lon;
    double speed;
    double course;
};
typedef struct gprmc gprmc_t;

struct location {
    double latitude;
    double longitude;
    double speed;
    double altitude;
    double course;
};
typedef struct location loc_t;

#endif