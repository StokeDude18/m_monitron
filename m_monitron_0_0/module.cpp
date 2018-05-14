#include "module.h"
#include "communication.h"
#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"

#include <QtWidgets>
#include <QApplication>
#include <string>

using namespace std;

module::module()//Constructeur par défaut, ne pas utiliser
{

}

//Constructeur remplissant les champs de type, position et ID de l'objet
module::module(uint8_t *byteArray)
{
    fillObjectParams(byteArray,0);//Passe la fonction zéro en deuxième paramètre
}

//Méthode utilisée pour convertir une trame découpée en octets vers les paramètres de l'objet module
void module::fillObjectParams(uint8_t *byteArray, uint8_t fonction)
{
    //Unions utilisées pour déconstruire la trame
    int32Tobytes u_IDconv;
    float2bytes  u_Reading;
    float2bytes  u_setpoint;
    float2bytes  u_varRate;
    int2bytes    u_cycle1;
    int2bytes    u_cycle2;
    float2bytes  u_cycle1_setpoint;
    float2bytes  u_cycle2_setpoint;
    float2bytes  u_calib1_raw;
    float2bytes  u_calib2_raw;
    float2bytes  u_calib1_converted;
    float2bytes  u_calib2_converted;
    float2bytes  u_current_read_mV;
    float2bytes  u_control_range;
    float2bytes  u_alarm_range;

    //Construction de l'ID à partir du tableau de bytes
    u_IDconv.b[0] = byteArray[r_id0];
    u_IDconv.b[1] = byteArray[r_id1];
    u_IDconv.b[2] = byteArray[r_id2];
    u_IDconv.b[3] = byteArray[r_id3];
    ID = u_IDconv.i;

    Type = byteArray[7];
    Position = byteArray[2];

    //Si fonction 1 ou 2
    if(fonction > 0 && fonction < 3)
    {
        //Déconstruit la trame selon et peuple les paramètres de l'objet

        u_Reading.b[0] = byteArray[9];
        u_Reading.b[1] = byteArray[10];
        u_Reading.b[2] = byteArray[11];
        u_Reading.b[3] = byteArray[12];
        Lecture = u_Reading.f;

        u_setpoint.b[0] = byteArray[13];
        u_setpoint.b[1] = byteArray[14];
        u_setpoint.b[2] = byteArray[15];
        u_setpoint.b[3] = byteArray[16];
        Setpoint = u_setpoint.f;

        switch(fonction)
        {
        case 1:
            u_varRate.b[0] = byteArray[17];
            u_varRate.b[1] = byteArray[18];
            u_varRate.b[2] = byteArray[19];
            u_varRate.b[3] = byteArray[20];
            Var_Rate = u_varRate.f;

            u_cycle1.b[0] = byteArray[f1Cycle1_1];
            u_cycle1.b[1] = byteArray[f1Cycle1_2];
            Cycles.Cycle1 = u_cycle1.i;

            u_cycle2.b[0] = byteArray[f1Cycle2_1];
            u_cycle2.b[1] = byteArray[f1Cycle2_2];
            Cycles.Cycle2 = u_cycle2.i;

            u_cycle1_setpoint.b[0] = byteArray[f1Setpoint1_1];
            u_cycle1_setpoint.b[1] = byteArray[f1Setpoint1_2];
            u_cycle1_setpoint.b[2] = byteArray[f1Setpoint1_3];
            u_cycle1_setpoint.b[3] = byteArray[f1Setpoint1_4];
            Cycles.Setpoint1 = u_cycle1_setpoint.f;

            u_cycle2_setpoint.b[0] = byteArray[f1Setpoint2_1];
            u_cycle2_setpoint.b[1] = byteArray[f1Setpoint2_2];
            u_cycle2_setpoint.b[2] = byteArray[f1Setpoint2_3];
            u_cycle2_setpoint.b[3] = byteArray[f1Setpoint2_4];
            Cycles.Setpoint2 = u_cycle2_setpoint.f;

            Cycles.Cycle_Mode_State = byteArray[f1StartCycle];

            u_calib1_raw.b[0] = byteArray[f1CalibLecture1_mV1];
            u_calib1_raw.b[1] = byteArray[f1CalibLecture1_mV2];
            u_calib1_raw.b[2] = byteArray[f1CalibLecture1_mV3];
            u_calib1_raw.b[3] = byteArray[f1CalibLecture1_mV4];
            Calib.raw_P1 = u_calib1_raw.f;

            u_calib2_raw.b[0] = byteArray[f1CalibLecture2_mV1];
            u_calib2_raw.b[1] = byteArray[f1CalibLecture2_mV2];
            u_calib2_raw.b[2] = byteArray[f1CalibLecture2_mV3];
            u_calib2_raw.b[3] = byteArray[f1CalibLecture2_mV4];
            Calib.raw_P2 = u_calib2_raw.f;

            cout << Calib.raw_P2 << endl;

            u_calib1_converted.b[0] = byteArray[f1CalibLecture1_C1];
            u_calib1_converted.b[1] = byteArray[f1CalibLecture1_C2];
            u_calib1_converted.b[2] = byteArray[f1CalibLecture1_C3];
            u_calib1_converted.b[3] = byteArray[f1CalibLecture1_C4];
            Calib.converted_P1 = u_calib1_converted.f;

            u_calib2_converted.b[0] = byteArray[f1CalibLecture2_C1];
            u_calib2_converted.b[1] = byteArray[f1CalibLecture2_C2];
            u_calib2_converted.b[2] = byteArray[f1CalibLecture2_C3];
            u_calib2_converted.b[3] = byteArray[f1CalibLecture2_C4];
            Calib.converted_P2 = u_calib2_converted.f;

            u_current_read_mV.b[0] = byteArray[f1LectureNow_mV1];
            u_current_read_mV.b[1] = byteArray[f1LectureNow_mV2];
            u_current_read_mV.b[2] = byteArray[f1LectureNow_mV3];
            u_current_read_mV.b[3] = byteArray[f1LectureNow_mV4];
            Reading_mV = u_current_read_mV.f;

            u_control_range.b[0] = byteArray[f1ControlRange1];
            u_control_range.b[1] = byteArray[f1ControlRange2];
            u_control_range.b[2] = byteArray[f1ControlRange3];
            u_control_range.b[3] = byteArray[f1ControlRange4];
            Control.Control_Range = u_control_range.f;

            u_alarm_range.b[0] = byteArray[f1AlarmRange1];
            u_alarm_range.b[1] = byteArray[f1AlarmRange2];
            u_alarm_range.b[2] = byteArray[f1AlarmRange3];
            u_alarm_range.b[3] = byteArray[f1AlarmRange4];
            Control.Alarm_Range = u_alarm_range.f;

            Control.Alarm = byteArray[f1Alarm];
            Control.OP_Mode = byteArray[f1OperatingMode];
            Control.Global_OP_Mode = byteArray[f1GlobalOperatingMode];
            break;
        case 2:
            Control.Alarm = byteArray[f2Alarm];
            break;

        }
    }
}



