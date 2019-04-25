#ifndef H_PID
#define H_PID

using namespace std;

class PID {
    public:
        PID();
        PID(float Kp, float Ki, float Kd);

        float getKp();
        float getKi();
        float getKd();
        void setKp(float Kp);
        void setKi(float Ki);
        void setKd(float Kd);

        float calcP(float setPoint, float input);
        float calcPI(float setPoint, float input);
        float calcPD(float setPoint, float input);
        float calcPID(float setPoint, float input);
    
    private:
        float Kp;
        float Ki;
        float Kd; 
        float previousError = 0;
        float sumOfError = 0;       
};

#endif