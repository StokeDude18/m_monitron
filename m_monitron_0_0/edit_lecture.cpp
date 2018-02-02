#include "edit_lecture.h"
#include "ui_settings_edit.h"
#include <QLineEdit>

Edit_Lecture::Edit_Lecture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings_Edit)
{
    ui->setupUi(this);
    ui->tb_new_setpoint->setValidator(new QDoubleValidator(0, 100, 2, this));
    ui->tb_new_var_rate->setValidator(new QDoubleValidator(0, 100, 2, this));
}

Edit_Lecture::~Edit_Lecture()
{
    delete ui;

}

