#ifndef MODULE_H
#define MODULE_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //UART //usleep
#include <fcntl.h> //UART
#include <string>
#include <cstring>

using namespace std;

class module
{
public:
    module();
    uint32_t ID;

    int8_t Type;
    int8_t Position;
    float Lecture;
    float Setpoint;
    int8_t OP_Mode;
    float Reading_mV;
    float Var_Rate;

    struct calibration {
        float raw_P1;
        float converted_P1;
        float raw_P2;
        float converted_P2;
    }Calib;

    void fillObjectParams(uint8_t* byteArray, uint8_t fonction);




private:

};

//module m;

#endif // MODULE_H
