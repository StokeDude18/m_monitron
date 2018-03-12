#include "edit_calibration.h"
#include "ui_edit_calibration.h"
#include <QLineEdit>
#include "communication.h"
#include <QString>

edit_Calibration::edit_Calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Calibration)
{
    QString qs_calib;
    ui->setupUi(this);
    ui->tb_P1_mV->setValidator(new QDoubleValidator(0, 5000, 2, this));
    ui->tb_P1_Convert_Unit->setValidator(new QDoubleValidator(0, 10000, 3, this));
    ui->tb_P2_mV->setValidator(new QDoubleValidator(0, 5000, 2, this));
    ui->tb_P2_Convert_Unit->setValidator(new QDoubleValidator(0, 10000, 3, this));

    qs_calib.sprintf("%.2f", m.Calib.raw_P1);
    ui->tb_P1_mV->setText(qs_calib);

    qs_calib.sprintf("%.2f", m.Calib.raw_P2);
    ui->tb_P2_mV->setText(qs_calib);

    qs_calib.sprintf("%.2f", m.Calib.converted_P1);
    ui->tb_P1_Convert_Unit->setText(qs_calib);

    qs_calib.sprintf("%.2f", m.Calib.converted_P2);
    ui->tb_P2_Convert_Unit->setText(qs_calib);
}

edit_Calibration::~edit_Calibration()
{
    delete ui;
}
