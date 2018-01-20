#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream> //COUT

#include <pthread.h> //pour thread
#include <unistd.h> //UART //usleep
#include <fcntl.h> //UART
#include <termios.h> //UART

#define DEBUG

#define NB_MODULE 6
#define NB_TRAME 70
#define T_SOH 1
#define T_EOH1 254
#define T_EOH2 255
#define R_SOH 123
#define FONCT0_TIME 10 //10 secondes
//module type
//#define TEMPERATURE 0

#define BROADCAST_TIME 100 // 10 secondes
//fonction
#define BROADCAST 0
#define ALL_INFORMATIONS 1
#define INFORMATIONS 2

//#define FONCTION0 

enum 
{
    r_soh=0,
    r_pos,
    r_id0,
    r_id1,
    r_id2,
    r_id3,
    r_type,
    r_fonction
};

enum
{
	t_soh=0,
	t_size,
	t_pos,
	t_fonction,
	t_checksum,
	t_eoh1,
	t_eoh2
};

using namespace std;

//string module[NB_MODULE] = {"Temperature", "Oxygene", "Salinite_Conductivite", "PH", "Debit", "Niveau"}; //noms des modules possibles

union float2bytes 
{ 
    float f; 
    char b[sizeof(float)]; 
};

union int2bytes
{
    int i;
    char b[sizeof(int)];
};


/* PROTOTYPES */
void *do_Receive(void *args);
void *do_Analyse(void* args);
void clear_RX();
void send_Fonction(int8_t r_pos, int8_t fonct);
char calcul_Checksum(char trame[], char t);
void print_TX();
void print_RX();
bool tableVerify(string name);
	/*float lecture;
    float setpoint;
    float taux_variation;
    int cycle1;
    float setpoint1;
    int cycle2;
    float setpoint2;
    byte start_cycles;
    float calib_lecture1_mV;
    float calib_lecture1_C;
    float calib_lecture2_mV;
    float calib_lecture2_C;
    float lecture_now_mV;
    float control_range;
    float alarms_range;
    byte alarms;
    byte operating_mode;
    byte g_operating_mode;
	String[] types = {"Temperature", "Oxygene", "Salinite_Conductivite", "PH", "Debit", "Niveau"};
	int type;
	
	enum val
	{
		lecture1=8,
    lecture2,
    lecture3,
    lecture4(((lecture3.getnum())+1)),
    setpoint1(((lecture4.getnum())+1)),
    setpoint2(((setpoint1.getnum())+1)),
    setpoint3(((setpoint2.getnum())+1)),
    setpoint4(((setpoint3.getnum())+1)),
    tauxVariation1(((setpoint4.getnum())+1)),
    tauxVariation2(((tauxVariation1.getnum())+1)),
    tauxVariation3(((tauxVariation2.getnum())+1)),
    tauxVariation4(((tauxVariation3.getnum())+1)),
    cycle1_1(((tauxVariation4.getnum())+1)),
    cycle1_2(((cycle1_1.getnum())+1)),
    setpoint1_1(((cycle1_2.getnum())+1)),
    setpoint1_2(((setpoint1_1.getnum())+1)),
    setpoint1_3(((setpoint1_2.getnum())+1)),
    setpoint1_4(((setpoint1_3.getnum())+1)),
    cycle2_1(((setpoint1_4.getnum())+1)),
    cycle2_2(((cycle2_1.getnum())+1)),
    setpoint2_1(((cycle2_2.getnum())+1)),
    setpoint2_2(((setpoint2_1.getnum())+1)),
    setpoint2_3(((setpoint2_2.getnum())+1)),
    setpoint2_4(((setpoint2_3.getnum())+1)),
    startCycles(((setpoint2_4.getnum())+1)),
    calibLecture1_mV1(((startCycles.getnum())+1)),
    calibLecture1_mV2(((calibLecture1_mV1.getnum())+1)),
    calibLecture1_mV3(((calibLecture1_mV2.getnum())+1)),
    calibLecture1_mV4(((calibLecture1_mV3.getnum())+1)),
    calibLecture1_C1(((calibLecture1_mV4.getnum())+1)),
    calibLecture1_C2(((calibLecture1_C1.getnum())+1)),
    calibLecture1_C3(((calibLecture1_C2.getnum())+1)),
    calibLecture1_C4(((calibLecture1_C3.getnum())+1)),
    calibLecture2_mV1(((calibLecture1_C4.getnum())+1)),
    calibLecture2_mV2(((calibLecture2_mV1.getnum())+1)),
    calibLecture2_mV3(((calibLecture2_mV2.getnum())+1)),
    calibLecture2_mV4(((calibLecture2_mV3.getnum())+1)),
    calibLecture2_C1(((calibLecture2_mV4.getnum())+1)),
    calibLecture2_C2(((calibLecture2_C1.getnum())+1)),
    calibLecture2_C3(((calibLecture2_C2.getnum())+1)),
    calibLecture2_C4(((calibLecture2_C3.getnum())+1)),
    lectureNow_mV1(((calibLecture2_C4.getnum())+1)),
    lectureNow_mV2(((lectureNow_mV1.getnum())+1)),
    lectureNow_mV3(((lectureNow_mV2.getnum())+1)),
    lectureNow_mV4(((lectureNow_mV3.getnum())+1)),
    controlRange1(((lectureNow_mV4.getnum())+1)),
    controlRange2(((controlRange1.getnum())+1)),
    controlRange3(((controlRange2.getnum())+1)),
    controlRange4(((controlRange3.getnum())+1)),
    alarmRange1(((controlRange4.getnum())+1)),
    alarmRange2(((alarmRange1.getnum())+1)),
    alarmRange3(((alarmRange2.getnum())+1)),
    alarmRange4(((alarmRange3.getnum())+1)),
    alarms(((alarmRange4.getnum())+1)),
    operationMode(((alarms.getnum())+1)),
    g_operationMode(((operationMode.getnum())+1));
	}*/
