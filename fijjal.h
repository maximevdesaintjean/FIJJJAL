#ifndef H_FIJJAL
#define H_FIJJAL

using namespace std;

class Fijjal {
    public:
        Fijjal();
        
        /* Ultrasound 1 */
        int ultra_echo1 = 27;
        int ultra_trig1 = 17;

        /* Ultrasound 2 */
        int ultra_echo2 = 26;
        int ultra_trig2 = 19;

        /* Ultrasound 3 */
        int ultra_echo3 = 0;
        int ultra_trig3 = 0;

        /* Ultrasound 4 */
        int ultra_echo4 = 0;
        int ultra_trig4 = 0;

        /* Motors */
        int motor_pin1 = 0;
        int motor_pin2 = 0;
        int motor_pin3 = 0;
        int motor_pin4 = 0;
};

#endif