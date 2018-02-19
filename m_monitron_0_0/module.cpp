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

void module::fillObjectParams(uint8_t *byteArray)
{
    int2bytes IDconv;
    //float2bytes lecture, setpoint;
    //IDconv.b = &byteArray[9];
    IDconv.b[0] = byteArray[3];
    IDconv.b[1] = byteArray[4];
    IDconv.b[2] = byteArray[5];
    IDconv.b[3] = byteArray[6];
    /*cout << int(IDconv.b[0]) << endl;
    cout << int(IDconv.b[1]) << endl;
    cout << int(IDconv.b[2]) << endl;
    cout << int(IDconv.b[3]) << endl;*/

    ID = IDconv.i;
   // cout << int32_t(ID);
    //cout << std::hex << int(IDconv.b[0]) << endl;
    Type = byteArray[7];
    Position = byteArray[2];
}

void module::updateObjectReading(uint8_t* readByteArray)
{
    float2bytes u_Reading;
    float2bytes u_setpoint;
    float2bytes u_varRate;


    u_Reading.b[0] = readByteArray[8];
    u_Reading.b[1] = readByteArray[9];
    u_Reading.b[2] = readByteArray[10];
    u_Reading.b[3] = readByteArray[11];
    Lecture = u_Reading.f;

    u_setpoint.b[0] = readByteArray[12];
    u_setpoint.b[1] = readByteArray[13];
    u_setpoint.b[2] = readByteArray[14];
    u_setpoint.b[3] = readByteArray[15];
    Setpoint = u_setpoint.f;

    u_varRate.b[0] = readByteArray[16];
    u_varRate.b[1] = readByteArray[17];
    u_varRate.b[2] = readByteArray[18];
    u_varRate.b[3] = readByteArray[19];
    Var_Rate = u_varRate.f;
}


