#include "edit_lecture.h"
#include "ui_edit_lecture.h"
#include <QLineEdit>

edit_Lecture::edit_Lecture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Lecture)
{
    ui->setupUi(this);
    ui->tb_new_setpoint->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_new_var_rate->setValidator(new QDoubleValidator(0,1000, 2));
}

edit_Lecture::~edit_Lecture()
{
    delete ui;
}
