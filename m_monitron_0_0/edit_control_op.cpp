#include "edit_control_op.h"
#include "ui_edit_control_op.h"
#include "communication.h"
#include <QString>

#include "numpad.h"
#include "ui_numpad.h"
#include "editline.h"

//Constructeur
edit_Control_OP::edit_Control_OP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Control_OP)
{    
    ui->setupUi(this);

    //Ajout d'un validateur dans les textbox d'édition de paramètres pour permettre
    //uniquement l'entrée de valeurs numériques
    ui->tb_New_Alarm_Range->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_New_Control_Range->setValidator(new QDoubleValidator(0,1000, 2));

    connect(ui->tb_New_Alarm_Range, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_New_Control_Range, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
}

edit_Control_OP::~edit_Control_OP()
{
    delete ui;
}

void edit_Control_OP::onFocus(bool hasFocus)
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
