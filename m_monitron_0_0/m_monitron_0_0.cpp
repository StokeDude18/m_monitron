#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "edit_lecture.h"
#include "edit_calibration.h"
#include "edit_control_op.h"

#include "ui_edit_lecture.h"
#include "ui_edit_cycles.h"
#include "ui_edit_calibration.h"
#include "ui_edit_control_op.h"

#include <QtWidgets>
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <exception>
#include <QtGui>

using namespace std;


m_monitron_0_0::m_monitron_0_0(QWidget *parent) : QMainWindow(parent), ui(new Ui::m_monitron_0_0)
{
    ui->setupUi(this);
    ui->sbar_Device_Informations->showMessage(tr("Device ID:        Position:       Sensor type: "));
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
          lecture = edit_w_Lecture.ui->tb_new_setpoint->text().toFloat();
        }
        catch(exception& e)
        {
            error_Msg_Box.setText("Please enter a valid value.");
            error_Msg_Box.exec();
        }          
    }
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
          calibP1_raw = edit_w_Calib.ui->tb_P1_mV->text().toFloat();
          calibP1_converted = edit_w_Calib.ui->tb_P1Convert_Unit->text().toFloat();
          calibP2_raw = edit_w_Calib.ui->tb_P2_mV->text().toFloat();
          calibP2_converted = edit_w_Calib.ui->tb_P2_Convert_Unit->text().toFloat();
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
