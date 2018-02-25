/*	File:	communication.h
 *	Author:	Alfred M.-Quintin
 *	Date:	Feb. 2018 
 *	
 *	Brief:	Fichier contenant les prototypes des fonctions définies dans
 *			le main et contenant toutes les définitions et constantes 
 *			reliées à la communication avec le module d'acquisition.
 *
 */


/*		   INCLUDES     	*/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream> //COUT
#include <pthread.h> //pour thread
#include <unistd.h> //UART //usleep
#include <fcntl.h> //UART
#include <termios.h> //UART
#include "module.h"


using namespace std;



/*			DEFINES			*/

#define NB_MODULE 6 
#define NB_TRAME 70 	//Nb d'octets transmis dans une trame
#define T_SOH 1			//SOH en transmission
#define T_EOH1 254		//Premier EOH en transmission
#define T_EOH2 255		//Deuxième EOH en transmission
#define R_SOH 123		//SOH en réception
#define FONCT0_TIME 10 	//Durée de l'acquisition des modules sur le bus can

#define BROADCAST_TIME 100 //Durée de l'acquisition des modules sur le bus can

#define GET_DEVICES 0	//Fonction d'acquisition des modules sur le bus can
#define GET_PARAMS 1	//Fonction d'acquisition de tous les paramètres contenus dans la carte SD d'un module
#define GET_READINGS 2	//Fonction de rafraîchissment des lectures faites par le module

//Types de modules
enum type : int8_t {Temperature, Oxygene, Salinite, PH, Debit, Niveau};

//Position des bytes en réception
enum 
{
    r_soh=0,
    r_size,
    r_pos,
    r_id0,
    r_id1,
    r_id2,
    r_id3,
    r_type,
    r_fonction
};

//Position des bytes en en envoi
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

//Fin de trame dans la réception suite à une requête de fonction 0 
enum trame0
{
    f0=8,
    f0Checksum,
    f0Eoh1,
    f0Eoh2
};


//Fin de trame dans la réception suite à une requête de fonction 1
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
    //Si plus de données ajoutées à la trame
    f1Checksum,
    f1Eoh1,
    f1Eoh2
};


//Fin de trame dans la réception suite à une requête de fonction 2
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
    //Si plus de données ajoutées à la trame
    f2Checksum,
    f2Eoh1,
    f2Eoh2
};


//Fin de trame dans la réception suite à une requête de fonction 3
enum trame3
{
    f3=8,
    f3Reponse,
    f3Checksum,
    f3Eoh1,
    f3Eoh2
};


//Fin de trame dans la réception suite à une requête de fonction 4
enum trame4
{
    f4=8,
    f4Reponse,
    f4Checksum,
    f4Eoh1,
    F4Eoh2
};

union float2bytes //Union pour la conversion de valeurs float en octets et vice versa
{ 
    float f; 
    uint8_t b[4];
};

union int2bytes //Union pour la conversion de valeurs int en octets et vice versa
{
    uint32_t i;
    uint8_t b[4];
};


/* PROTOTYPES */
void *do_Receive(void *args);						//Thread de réception des données
void *mainTask(void *args);							//Thread principal (logique d'alternance réception/envoi)
void clear_RX();									//Flush du buffer de réception
void send_Fonction(int8_t r_pos, int8_t fonct);		//Fonction d'envoi vers le module d'acquisition
uint8_t calcul_Checksum(uint8_t* trame, char t);	//Fonction de calcul du checksum
void print_TX();									//Fonction d'affichage du contenu envoyé dans le terminal
void print_RX();									//Fonction d'affichage du contenu reçu dans le terminal	
bool tableVerify(string name);						//Fonction de vérification d'existence d'un nom de table associé à un module 


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
