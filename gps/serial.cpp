#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include "serial.h"

using namespace std;

Serial::Serial() {
}

void Serial::serialInit(char *bus){
    this->file = open(bus, O_RDWR | O_NOCTTY | O_NDELAY);
    serialConfig();
}

void Serial::serialConfig(void)
{
    struct termios options;
    tcgetattr(this->file, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(this->file, TCIFLUSH);
    tcsetattr(this->file, TCSANOW, &options);
}

void Serial::serialPrint(const char *line, int len)
{
    if (this->file != -1) {
        char *cpstr = (char *)malloc((len+1) * sizeof(char));
        strcpy(cpstr, line);
        cpstr[len-1] = '\r';
        cpstr[len] = '\n';

        int count = write(this->file, cpstr, len+1);
        free(cpstr);
    }
}

void Serial::serialRead(char *buffer, int len)
{
    char c;
    char *b = buffer;
    int rx_length = -1;
    while(1) {
        rx_length = read(this->file, (void*)(&c), 1);

        if (rx_length <= 0) {
            sleep(1);
        } else {
            if (c == '\n') {
                *b++ = '\0';
                break;
            }
            *b++ = c;
        }
    }
}

void Serial::serialClose(void)
{
    close(this->file);
}
