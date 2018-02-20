#include "module.h"
#include "communication.h"
#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"

#include <QtWidgets>
#include <QApplication>
#include <string>

using namespace std;

module::module()
{

}

void module::fillObjectParams(uint8_t *byteArray, uint8_t fonction)
{
    int2bytes IDconv;
    float2bytes u_Reading;
    float2bytes u_setpoint;
    float2bytes u_varRate;

    IDconv.b[0] = byteArray[r_id0];
    IDconv.b[1] = byteArray[r_id1];
    IDconv.b[2] = byteArray[r_id2];
    IDconv.b[3] = byteArray[r_id3];

    ID = IDconv.i;

    Type = byteArray[7];
    Position = byteArray[2];

    switch(fonction)
    {
    case 1:
        break;
    case 2:
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

        u_varRate.b[0] = byteArray[17];
        u_varRate.b[1] = byteArray[18];
        u_varRate.b[2] = byteArray[19];
        u_varRate.b[3] = byteArray[20];
        Var_Rate = u_varRate.f;
        break;
    }
}



