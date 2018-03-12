#include "edit_cycles.h"
#include "ui_edit_cycles.h"
#include "communication.h"
#include <QString>

edit_Cycles::edit_Cycles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Cycles)
{
    QString qs_cycles;
    ui->setupUi(this);
    ui->tb_Cycle1->setValidator(new QIntValidator(0,1000));
    ui->tb_Cycle2->setValidator(new QIntValidator(0,1000));
    ui->tb_Setpoint1->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Setpoint2->setValidator(new QDoubleValidator(0,1000, 2));

    qs_cycles.sprintf("%d", m.Cycles.Cycle1);
    ui->tb_Cycle1->setText(qs_cycles);

    qs_cycles.sprintf("%d", m.Cycles.Cycle2);
    ui->tb_Cycle2->setText(qs_cycles);

    qs_cycles.sprintf("%.2f", m.Cycles.Setpoint1);
    ui->tb_Setpoint1->setText(qs_cycles);

    qs_cycles.sprintf("%.2f", m.Cycles.Setpoint2);
    ui->tb_Setpoint2->setText(qs_cycles);
}

edit_Cycles::~edit_Cycles()
{
    delete ui;
}
