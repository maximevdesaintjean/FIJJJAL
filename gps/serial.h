#ifndef SERIAL_H
#define SERIAL_H

using namespace std;

class Serial 
{
    public:
        Serial();

        void serialInit(char *bus);  
        
        void serialPrint(const char *, int);
        void serialRead(char *, int);
        void serialClose();

    private:
        int file;
        void serialConfig();
};
#endif
