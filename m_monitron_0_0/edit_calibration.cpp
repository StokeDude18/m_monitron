#include "edit_calibration.h"
#include "ui_edit_calibration.h"
#include <QLineEdit>

edit_Calibration::edit_Calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Calibration)
{
    ui->setupUi(this);
    ui->tb_P1_mV->setValidator(new QDoubleValidator(0, 5000, 2, this));
    ui->tb_P1Convert_Unit->setValidator(new QDoubleValidator(0, 10000, 3, this));
    ui->tb_P2_mV->setValidator(new QDoubleValidator(0, 5000, 2, this));
    ui->tb_P2_Convert_Unit->setValidator(new QDoubleValidator(0, 10000, 3, this));
}

edit_Calibration::~edit_Calibration()
{
    delete ui;
}
