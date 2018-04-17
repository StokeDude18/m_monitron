#include "edit_lecture.h"
#include "ui_edit_lecture.h"
#include "communication.h"
#include <QString>

#include "numpad.h"
#include "ui_numpad.h"
#include "editline.h"


//Constructeur
edit_Lecture::edit_Lecture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Lecture)
{    
    ui->setupUi(this);

    ui->tb_new_setpoint->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_new_var_rate->setValidator(new QDoubleValidator(0,1000, 2));
    connect(ui->tb_new_setpoint, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_new_var_rate, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
}

edit_Lecture::~edit_Lecture()
{
    delete ui;
}




void edit_Lecture::onFocus(bool hasFocus)
{
    EditLine *edlObj = (EditLine *)sender();
    Numpad num;

    if(hasFocus == true)
    {
        num.exec();
        if(num.result() == QDialog::Accepted)
            edlObj->setText(num.ui->le_Entry->text());
        ui->buttonBox->setFocus();
    }
}


