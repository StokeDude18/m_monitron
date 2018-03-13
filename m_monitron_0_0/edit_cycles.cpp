#include "edit_cycles.h"
#include "ui_edit_cycles.h"
#include "communication.h"
#include <QString>

edit_Cycles::edit_Cycles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Cycles)
{
    ui->setupUi(this);
    ui->tb_Cycle1->setValidator(new QIntValidator(0,1000));
    ui->tb_Cycle2->setValidator(new QIntValidator(0,1000));
    ui->tb_Setpoint1->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Setpoint2->setValidator(new QDoubleValidator(0,1000, 2));
}

edit_Cycles::~edit_Cycles()
{
    delete ui;
}
