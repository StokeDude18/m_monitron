/*#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>*/
#include "communication.h"

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

//extern enum start;
//using namespace std;

enum trame0
{
    f0=8,
    f0Checksum,
    f0Eoh1,
    f0Eoh2
};

enum trame1
{
    f1=8,
    f1Lecture1,
    f1Lecture2,
    f1Lecture3,
    f1Lecture4,
    f1Setpoint1,
    f1Setpoint2,
    f1Setpoint3,
    f1Setpoint4,
    f1TauxVariation1,
    f1TauxVariation2,
    f1TauxVariation3,
    f1TauxVariation4,
    f1Cycle1_1,
    f1Cycle1_2,
    f1Setpoint1_1,
    f1Setpoint1_2,
    f1Setpoint1_3,
    f1Setpoint1_4,
    f1Cycle2_1,
    f1Cycle2_2,
    f1Setpoint2_1,
    f1Setpoint2_2,
    f1Setpoint2_3,
    f1Setpoint2_4,  
    f1StartCycle,
    f1CalibLecture1_mV1,
    f1CalibLecture1_mV2,
    f1CalibLecture1_mV3,
    f1CalibLecture1_mV4,
    f1CalibLecture1_C1,
    f1CalibLecture1_C2,
    f1CalibLecture1_C3,
    f1CalibLecture1_C4,
    f1CalibLecture2_mV1,
    f1CalibLecture2_mV2,
    f1CalibLecture2_mV3,
    f1CalibLecture2_mV4,
    f1CalibLecture2_C1,
    f1CalibLecture2_C2,
    f1CalibLecture2_C3,
    f1CalibLecture2_C4,
    f1LectureNow_mV1,
    f1LectureNow_mV2,
    f1LectureNow_mV3,
    f1LectureNow_mV4,
    f1ControlRange1,
    f1ControlRange2,
    f1ControlRange3,
    f1ControlRange4,
    f1AlarmRange1,
    f1AlarmRange2,
    f1AlarmRange3,
    f1AlarmRange4,
    f1Alarm, 
    f1OperatingMode,
    f1GlobalOperatingMode,
    //si ajout de data, c'est ici
    f1Checksum,
    f1Eoh1,
    f1Eoh2
};

enum trame2
{
    f2=8,
    f2Lecture1,
    f2Lecture2,
    f2Lecture3,
    f2Lecture4,
    f2Setpoint1,
    f2Setpoint2,
    f2Setpoint3,
    f2Setpoint4,
    f2Alarm,
    //si ajout de data, c'est ici
    f2Checksum,
    f2Eoh1,
    f2Eoh2
};

enum trame3
{
    f3=8,
    f3Reponse,
    f3Checksum,
    f3Eoh1,
    f3Eoh2
};

enum trame4
{
    f4=8,
    f4Reponse,
    f4Checksum,
    f4Eoh1,
    F4Eoh2
};

class temperature
{
	public:
		temperature(int8_t trame[]);
		string getName();

	private:
		string name;
		int8_t position;
		int2bytes id;
		float lecture;
        float setpoint;
        float taux_variation;
     	int cycle1;
	    float setpoint1;
	    int cycle2;
	    float setpoint2;
	    int8_t start_cycles;
	    float calib_lecture1_mV;
	    float calib_lecture1_C;
	    float calib_lecture2_mV;
	    float calib_lecture2_C;
	    float lecture_now_mV;
	    float control_range;
	    float alarms_range;
	    int8_t alarms;
	    int8_t operating_mode;
	    int8_t g_operating_mode;

};

#endif 
