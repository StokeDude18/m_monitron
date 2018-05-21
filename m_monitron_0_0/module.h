/*	File:	module.h
 *	Author:	Alfred M.-Quintin
 *	Date:	Avril 2018
 *
 *	Brief:	Fichier contenant les prototypes des méthodes de la classe module,
 *          ainsi que toutes les variables membres de celle-ci
 *
 */

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
    module(uint8_t *byteArray);
    uint32_t ID;

    int8_t Type;
    int8_t Position;
    float Lecture;
    float Setpoint;    
    float Reading_mV;
    float Var_Rate;

    struct cycles {
        int Cycle1;
        int Cycle2;
        float Setpoint1;
        float Setpoint2;
        int8_t Cycle_Mode_State;
    }Cycles;

    struct calibration {
        float raw_P1;
        float converted_P1;
        float raw_P2;
        float converted_P2;
    }Calib;

    struct control {
        float Control_Range;
        float Alarm_Range;
        int8_t Alarm;
        int8_t OP_Mode;
        int8_t Global_OP_Mode;
    }Control;

    static int moduleCounter;

    void fillObjectParams(uint8_t* byteArray, uint8_t fonction);
private:


};

//module m;

#endif // MODULE_H
