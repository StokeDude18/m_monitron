#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "edit_lecture.h"
#include "edit_calibration.h"
#include "edit_control_op.h"

#include "ui_edit_lecture.h"
#include "ui_edit_cycles.h"
#include "ui_edit_calibration.h"
#include "ui_edit_control_op.h"
#include "communication.h"

#include <QtWidgets>
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <exception>
#include <QtGui>
#include <QString>

using namespace std;


m_monitron_0_0::m_monitron_0_0(QWidget *parent) : QMainWindow(parent), ui(new Ui::m_monitron_0_0)
{
    ui->setupUi(this);
    ui->sbar_Device_Informations->showMessage(tr("Device ID:        Position:       Sensor type: "));  
    nextFunction = 2;
}

m_monitron_0_0::~m_monitron_0_0()
{
    delete ui;
}

void m_monitron_0_0::on_b_Edit_tLecture_clicked()
{    
    edit_w_Lecture.exec();

    if(edit_w_Lecture.result() == QDialog::Accepted)
    {
        try
        {
          m_newParams.Setpoint = edit_w_Lecture.ui->tb_new_setpoint->text().toFloat();
        }
        catch(exception& e)
        {
            error_Msg_Box.setText("Please enter a valid value.");
            error_Msg_Box.exec();
        }          
    }
    //ui->sbar_Device_Informations
}

void m_monitron_0_0::on_b_Edit_tCycles_clicked()
{
    edit_w_Cycles.exec();

    if(edit_w_Cycles.result() == QDialog::Accepted)
    {

    }
}

void m_monitron_0_0::on_b_Edit_tCalibration_clicked()
{
    edit_w_Calib.exec();

    if(edit_w_Calib.result() == QDialog::Accepted)
    {
        try
        {
          m_newParams.Calib.raw_P1 = edit_w_Calib.ui->tb_P1_mV->text().toFloat();
          m_newParams.Calib.converted_P1 = edit_w_Calib.ui->tb_P1Convert_Unit->text().toFloat();
          m_newParams.Calib.raw_P2 = edit_w_Calib.ui->tb_P2_mV->text().toFloat();
          m_newParams.Calib.converted_P2 = edit_w_Calib.ui->tb_P2_Convert_Unit->text().toFloat();
        }
        catch(exception& e)
        {
            error_Msg_Box.setText("Please enter a valid value.");
            error_Msg_Box.exec();
        }
    }
}

void m_monitron_0_0::on_b_Edit_tControl_clicked()
{
    edit_w_ControlOP.exec();
    if(edit_w_ControlOP.result() == QDialog::Accepted)
    {

    }
}

void m_monitron_0_0::printParams(module* mod, uint8_t fonction)
{

    //string qs = "Device ID: " + to_string(mod->ID) + "  Position: " + to_string((char)mod->Position) + "  Type: " + to_string((char)mod->Type);
    char module_type[20];
    QString qs;// = QString("Device ID: %1  Position: %2  Type: %3").arg(to_string(mod->ID), to_string((char)mod->Position), to_string((char)mod->Type));
    switch(mod->Type)
    {
    case 0:
        sprintf(module_type, "Temperature");

        break;
    case 1:
        sprintf(module_type, "Oxygene");
        //module_type = "Oxygene";
        break;
    case 2:
        sprintf(module_type, "Salinite");
        //module_type = "Salinite";
        break;
    case 3:
        sprintf(module_type, "PH");
        //module_type = "PH";
        break;
    case 4:
        sprintf(module_type, "Debit");
        //module_type = "Debit";
        break;
    case 5:
        sprintf(module_type, "Niveau");
        //module_type = "Niveau";

    }

    qs.sprintf("Device ID: %u  Position: %d  Type: %s", mod->ID, mod->Position, module_type);
    ui->sbar_Device_Informations->showMessage(qs);

    if(fonction > 0)
    {
        qs.sprintf("%.2f", mod->Lecture);
        ui->l_current_Reading->setText(qs);
        qs.sprintf("%.2f", mod->Setpoint);
        ui->l_Current_Setpoint->setText(qs);
        qs.sprintf("%.2f", mod->Var_Rate);
        ui->l_Current_Var_Rate->setText(qs);
    }
}

uint8_t m_monitron_0_0::getNextFunction()
{
    return nextFunction;
}

void m_monitron_0_0::getNewParams(module *objNewParams)
{
    objNewParams = &m_newParams;
}
