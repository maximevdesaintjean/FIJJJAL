#ifndef H_PID
#define H_PID

using namespace std;

class PID {
    public:
        PID();
        PID(float minBound, float maxBound, float Kp, float Ki, float Kd);

        float getMinBound();
        float getMaxBound();
        float getKp();
        float getKi();
        float getKd();

        void setMinBound(float minBound);
        void setMaxBound(float maxBound);
        void setKp(float Kp);
        void setKi(float Ki);
        void setKd(float Kd);

        float calcP(float setPoint, float input);
        float calcPI(float setPoint, float input);
        float calcPD(float setPoint, float input);
        float calcPID(float setPoint, float input);
    
    private:
        float minBound;
        float maxBound;
        int errorMax = 10;
        float Kp;
        float Ki;
        float Kd; 
        float previousError = 0;
        float cycle = 1;
        float sumOfError = 0;

        float calcMap(float output);       
};

#endif