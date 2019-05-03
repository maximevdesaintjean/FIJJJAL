#ifndef H_GYRO
#define H_GYRO

using namespace std;

class Gyro {
    public:
        Gyro();

        struct XY
        {
            int x;
            int y;
        };



        void initialise();
        void readXY();

        XY xy;

        
    private:
        int file;

        void i2cInitialise(char *bus, char address);
        int readAxis(char lsb_add, char msb_add);

       
};

#endif