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
    //ui->sbar_Device_Informations->showMessage(tr("Device ID:        Position:       Sensor type: "));
    nextFunction = 2;
}

m_monitron_0_0::~m_monitron_0_0()
{
    delete ui;
}

void m_monitron_0_0::on_b_Edit_tLecture_clicked()
{    
    QString qs_lecture;
    qs_lecture.sprintf("%.2f", m.Setpoint);
    edit_w_Lecture.ui->tb_new_setpoint->setText(qs_lecture);

    qs_lecture.sprintf("%.2f", m.Var_Rate);
    edit_w_Lecture.ui->tb_new_var_rate->setText(qs_lecture);

    edit_w_Lecture.exec();

    if(edit_w_Lecture.result() == QDialog::Accepted)
    {
        try
        {
          m_newParams.Setpoint = edit_w_Lecture.ui->tb_new_setpoint->text().toFloat();
          m_newParams.Var_Rate = edit_w_Lecture.ui->tb_new_var_rate->text().toFloat();
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
    QString qs_cycles;

    qs_cycles.sprintf("%u", m.Cycles.Cycle1);
    edit_w_Cycles.ui->tb_Cycle1->setText(qs_cycles);

    qs_cycles.sprintf("%u", m.Cycles.Cycle2);
    edit_w_Cycles.ui->tb_Cycle2->setText(qs_cycles);

    qs_cycles.sprintf("%.2f", m.Cycles.Setpoint1);
    edit_w_Cycles.ui->tb_Setpoint1->setText(qs_cycles);

    qs_cycles.sprintf("%.2f", m.Cycles.Setpoint2);
    edit_w_Cycles.ui->tb_Setpoint2->setText(qs_cycles);

    edit_w_Cycles.exec();

    if(edit_w_Cycles.result() == QDialog::Accepted)
    {
        try
        {
            m_newParams.Cycles.Cycle1 = edit_w_Cycles.ui->tb_Cycle1->text().toInt();
            m_newParams.Cycles.Cycle2 = edit_w_Cycles.ui->tb_Cycle2->text().toInt();
            m_newParams.Cycles.Setpoint1 = edit_w_Cycles.ui->tb_Setpoint1->text().toFloat();
            m_newParams.Cycles.Setpoint2 = edit_w_Cycles.ui->tb_Setpoint2->text().toFloat();
        }
        catch(exception& e)
        {
            error_Msg_Box.setText("Please enter a valid value.");
            error_Msg_Box.exec();
        }
    }
}

void m_monitron_0_0::on_b_Edit_tCalibration_clicked()
{
    QString qs_calib;
    qs_calib.sprintf("%.2f", m.Calib.raw_P1);
    edit_w_Calib.ui->tb_P1_mV->setText(qs_calib);

    qs_calib.sprintf("%.2f", m.Calib.raw_P2);
    edit_w_Calib.ui->tb_P2_mV->setText(qs_calib);

    qs_calib.sprintf("%.2f", m.Calib.converted_P1);
    edit_w_Calib.ui->tb_P1_Convert_Unit->setText(qs_calib);

    qs_calib.sprintf("%.2f", m.Calib.converted_P2);
    edit_w_Calib.ui->tb_P2_Convert_Unit->setText(qs_calib);
    edit_w_Calib.exec();

    if(edit_w_Calib.result() == QDialog::Accepted)
    {
        try
        {
          m_newParams.Calib.raw_P1 = edit_w_Calib.ui->tb_P1_mV->text().toFloat();
          m_newParams.Calib.converted_P1 = edit_w_Calib.ui->tb_P1_Convert_Unit->text().toFloat();
          m_newParams.Calib.raw_P2 = edit_w_Calib.ui->tb_P2_mV->text().toFloat();
          m_newParams.Calib.converted_P2 = edit_w_Calib.ui->tb_P2_Convert_Unit->text().toFloat();
          //nextFunction = f3;
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
    QString qs_control;
    qs_control.sprintf("%.2f", m.Control.Alarm_Range);
    edit_w_ControlOP.ui->tb_New_Alarm_Range->setText(qs_control);

    qs_control.sprintf("%.2f", m.Control.Control_Range);
    edit_w_ControlOP.ui->tb_New_Control_Range->setText(qs_control);
    edit_w_ControlOP.exec();
    if(edit_w_ControlOP.result() == QDialog::Accepted)
    {
        try
        {
            m_newParams.Control.Alarm_Range = edit_w_ControlOP.ui->tb_New_Alarm_Range->text().toFloat();
            m_newParams.Control.Control_Range = edit_w_ControlOP.ui->tb_New_Control_Range->text().toFloat();
            m_newParams.Control.Alarm = (edit_w_ControlOP.ui->cb_Alarm_Mode->currentText() == "Enabled") ? 1 : 0;
            m_newParams.Control.OP_Mode = (edit_w_ControlOP.ui->cb_OP_Mode->currentText() == "Enabled") ? 1 : 0;
            m_newParams.Control.Global_OP_Mode = (edit_w_ControlOP.ui->cb_GOP_Mode->currentText() == "Enabled") ? 1 : 0;
        }
        catch(exception& e)
        {
            error_Msg_Box.setText("Please enter a valid value.");
            error_Msg_Box.exec();
        }
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

    qs.sprintf("Device ID: %u  Position: %d  Type: %s   G. Op. Mode: %s", mod->ID, mod->Position, module_type, (mod->Control.Global_OP_Mode == 0) ? "Disabled" : "Enabled");
    ui->sbar_Device_Informations->showMessage(qs);

    if(fonction > 0)
    {
        qs.sprintf("%.2f", mod->Lecture);
        ui->l_current_Reading->setText(qs);
        qs.sprintf("%.2f", mod->Setpoint);
        ui->l_Current_Setpoint->setText(qs);
        qs.sprintf("%.2f", mod->Var_Rate);
        ui->l_Current_Var_Rate->setText(qs);

        if(fonction == 1)
        {
            qs.sprintf("%u", mod->Cycles.Cycle1);
            ui->l_Current_Cycle_1->setText(qs);

            qs.sprintf("%u", mod->Cycles.Cycle2);
            ui->l_Current_Cycle_2->setText(qs);

            qs.sprintf("%.2f", mod->Cycles.Setpoint1);
            ui->l_Current_Cycle_Setpoint_1->setText(qs);

            qs.sprintf("%.2f", mod->Cycles.Setpoint2);
            ui->l_Current_Cycle_Setpoint_2->setText(qs);

            ui->l_Cycle_Mode_Current_State->setText((mod->Cycles.Cycle_Mode_State == 1) ? "ON" : "OFF");

            qs.sprintf("%.2f", mod->Calib.raw_P1);
            ui->l_Current_P1_raw->setText(qs);

            qs.sprintf("%.2f", mod->Calib.converted_P1);
            ui->l_Current_P1_converted->setText(qs);

            qs.sprintf("%.2f", mod->Calib.raw_P2);
            ui->l_Current_P2_raw->setText(qs);

            qs.sprintf("%.2f", mod->Calib.converted_P2);
            ui->l_Current_P2_converted->setText(qs);

            qs.sprintf("%.2f", mod->Reading_mV);
            ui->l_Lecture_mV_Current->setText(qs);

            qs.sprintf("%.2f", mod->Control.Control_Range);
            ui->l_Current_Control_Range->setText(qs);

            qs.sprintf("%.2f", mod->Control.Alarm_Range);
            ui->l_Current_Alarm_Range->setText(qs);

            ui->l_Current_Operation_Mode->setText((mod->Control.OP_Mode == 1) ? "Enabled": "Disabled");

            ui->l_Current_Gloabal_Operation_Mode->setText((mod->Control.Global_OP_Mode == 1) ? "Enabled": "Disabled");

            m_newParams = *mod;
        }
    }
}

uint8_t m_monitron_0_0::getNextFunction()
{
    return nextFunction;
}

void m_monitron_0_0::setNextFunction(uint8_t function)
{
    if(function >= 0 && function <= 4)
        nextFunction = function;
}

void m_monitron_0_0::getNewParams(module *objNewParams)
{
    objNewParams = &m_newParams;
}

void m_monitron_0_0::buildF3Frame(uint8_t* sendBuffer)
{
    float2bytes  u_setpoint;
    float2bytes  u_varRate;
    int2bytes    u_cycle1;
    int2bytes    u_cycle2;
    float2bytes  u_cycle1_setpoint;
    float2bytes  u_cycle2_setpoint;
    /*float2bytes  u_calib1_raw;
    float2bytes  u_calib2_raw;
    float2bytes  u_calib1_converted;
    float2bytes  u_calib2_converted;*/
    float2bytes  u_control_range;
    float2bytes  u_alarm_range;

    u_setpoint.f = m_newParams.Setpoint;
    printf("Setpoint: %f\n", m_newParams.Setpoint);
    sendBuffer[t3_Setpoint1] = u_setpoint.b[0];
    sendBuffer[t3_Setpoint2] = u_setpoint.b[1];
    sendBuffer[t3_Setpoint3] = u_setpoint.b[2];
    sendBuffer[t3_Setpoint4] = u_setpoint.b[3];

    u_varRate.f = m_newParams.Var_Rate;
    sendBuffer[t3_VarRate1]  = u_varRate.b[0];
    sendBuffer[t3_VarRate2]  = u_varRate.b[1];
    sendBuffer[t3_VarRate3]  = u_varRate.b[2];
    sendBuffer[t3_VarRate4]  = u_varRate.b[3];

    u_cycle1.i = m_newParams.Cycles.Cycle1;
    sendBuffer[t3_Cycle1_1]  = u_cycle1.b[0];
    sendBuffer[t3_Cycle1_2]  = u_cycle1.b[1];

    u_cycle2.i = m_newParams.Cycles.Cycle2;
    sendBuffer[t3_Cycle2_1]  = u_cycle2.b[0];
    sendBuffer[t3_Cycle2_2]  = u_cycle2.b[1];

    u_cycle1_setpoint.f = m_newParams.Cycles.Setpoint1;
    sendBuffer[t3_Setpoint1_1]  = u_cycle1_setpoint.b[0];
    sendBuffer[t3_Setpoint1_2]  = u_cycle1_setpoint.b[1];
    sendBuffer[t3_Setpoint1_3]  = u_cycle1_setpoint.b[2];
    sendBuffer[t3_Setpoint1_4]  = u_cycle1_setpoint.b[3];

    u_cycle2_setpoint.f = m_newParams.Cycles.Setpoint2;
    sendBuffer[t3_Setpoint2_1]  = u_cycle2_setpoint.b[0];
    sendBuffer[t3_Setpoint2_2]  = u_cycle2_setpoint.b[1];
    sendBuffer[t3_Setpoint2_3]  = u_cycle2_setpoint.b[2];
    sendBuffer[t3_Setpoint2_4]  = u_cycle2_setpoint.b[3];

    /*u_calib1_raw.f = m_newParams.Calib.raw_P1;
    u_calib2_raw.f = m_newParams.Calib.raw_P2;
    u_calib1_converted.f = m_newParams.Calib.converted_P1;
    u_calib2_converted.f = m_newParams.Calib.converted_P2;*/

    u_control_range.f = m_newParams.Control.Control_Range;
    sendBuffer[t3_ControlRange1] = u_control_range.b[0];
    sendBuffer[t3_ControlRange2] = u_control_range.b[1];
    sendBuffer[t3_ControlRange3] = u_control_range.b[2];
    sendBuffer[t3_ControlRange4] = u_control_range.b[3];

    u_alarm_range.f = m_newParams.Control.Alarm_Range;
    sendBuffer[t3_AlarmRange1] = u_alarm_range.b[0];
    sendBuffer[t3_AlarmRange2] = u_alarm_range.b[1];
    sendBuffer[t3_AlarmRange3] = u_alarm_range.b[2];
    sendBuffer[t3_AlarmRange4] = u_alarm_range.b[3];

    sendBuffer[t3_OP_Mode] = m_newParams.Control.OP_Mode;
}


void m_monitron_0_0::on_b_Apply_Changes_clicked()
{
    nextFunction = 3;
}
