#ifndef _PS3conOS6_H_
#define _PS3conOS6_H_

#include "mbed.h"

/*#if MBED_MAJOR_VERSION >= 6
class PS3 : public BufferedSerial
#else*/
class PS3 : public UnbufferedSerial
//#endif
{
public:
    
    enum{
        UP,
        DOWN,
        RIGHT,
        LEFT,
        TRIANGLE,
        CROSS,
        CIRCLE,
        SQUARE,
        L1,
        L2,
        R1,
        R2,
        START,
        SELECT,
        LEFT_ANALOG_X,//14
        LEFT_ANALOG_Y,
        RIGHT_ANALOG_X,
        RIGHT_ANALOG_Y,
        MAX_BUTTON
    };
    
    enum{
        L_HIGH = -3,
        L_MIDDLE,
        L_LOW,
        NEUTRAL,
        R_LOW,
        R_MIDDLE,
        R_HIGH
    };
    
    enum{
        U_HIGH = -3,
        U_MIDDLE,
        U_LOW,
        D_LOW = 1,
        D_MIDDLE,
        D_HIGH
    };
    
    PS3(PinName rx, PinName connect, int rate = 2400);
    
    int check_connection();
    int get_data(int* data_p);
    void get_analog(int* analog);
    
private:
    
    DigitalIn _connect;
    
    int j;
    int check;
    int FREE[8];
    int ps3_data[8];
    int result[MAX_BUTTON];
    void initialization();
    void reference();
    
};

#endif
