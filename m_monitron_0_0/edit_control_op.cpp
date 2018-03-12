#include "edit_control_op.h"
#include "ui_edit_control_op.h"
#include "communication.h"
#include <QString>

edit_Control_OP::edit_Control_OP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Control_OP)
{
    QString qs_control;
    ui->setupUi(this);
    ui->tb_New_Alarm_Range->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_New_Control_Range->setValidator(new QDoubleValidator(0,1000, 2));

    qs_control.sprintf("%.2f", m.Control.Alarm_Range);
    ui->tb_New_Alarm_Range->setText(qs_control);

    qs_control.sprintf("%.2f", m.Control.Control_Range);
    ui->tb_New_Control_Range->setText(qs_control);
}

edit_Control_OP::~edit_Control_OP()
{
    delete ui;
}
