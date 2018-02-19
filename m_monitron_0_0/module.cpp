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

void module::fillObjectParams(int8_t byteArray)
{
    int2bytes IDconv;
    //float2bytes lecture, setpoint;
    //IDconv.b = &byteArray[9];
    IDconv.b[0] = byteArray[9];
    IDconv.b[1] = byteArray[10];
    IDconv.b[2] = byteArray[11];
    IDconv.b[3] = byteArray[12];
    ID = IDconv.i;
    cout << std::hex << int(IDconv.b[0]) << endl;
    Type = byteArray[7];
    Position = byteArray[2];
}


