#ifndef H_MOTOR
#define H_MOTOR

using namespace std;

class Motor {
    public:
        Motor(int pin);

        void initialize();
        void start();
        void stop();
        void setPWM(int value);
     
    private:
        int pin;
};

#endif