#include <stdio.h>
#include <stdlib.h>

#include "gps.h"
#include "struct.h"

int main(void) {
    // Open
    Gps gps = Gps();
    gps.gpsInit();

    loc_t data;

    while (1) {
        gps.gpsLocation(&data);

        printf("%lf %lf\n", data.latitude, data.longitude);
    }

    return EXIT_SUCCESS;
}