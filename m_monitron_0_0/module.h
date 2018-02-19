#ifndef MODULE_H
#define MODULE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //UART //usleep

using namespace std;

class module
{
public:
    module();
    int8_t ID;
    enum type : int8_t {Temperature, Oxygene, Salinite, PH, Debit, Niveau};
    int8_t Type;
    int8_t Position;
    float Lecture;
    float Setpoint;
    int8_t OP_Mode;
    float Reading_mV;

    struct calibration {
        float raw_P1;
        float converted_P1;
        float raw_P2;
        float converted_P2;
    }Calib;

    void fillObjectParams(int8_t byteArray);





private:

};

//module m;

#endif // MODULE_H
