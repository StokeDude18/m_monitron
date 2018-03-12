#include "edit_lecture.h"
#include "ui_edit_lecture.h"
#include <QLineEdit>
#include "communication.h"
#include <QString>

edit_Lecture::edit_Lecture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Lecture)
{
    QString qs_lecture;
    ui->setupUi(this);
    ui->tb_new_setpoint->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_new_var_rate->setValidator(new QDoubleValidator(0,1000, 2));

    qs_lecture.sprintf("%.2f", m.Setpoint);
    ui->tb_new_setpoint->setText(qs_lecture);

    qs_lecture.sprintf("%.2f", m.Var_Rate);
    ui->tb_new_var_rate->setText(qs_lecture);
}

edit_Lecture::~edit_Lecture()
{
    delete ui;
}
