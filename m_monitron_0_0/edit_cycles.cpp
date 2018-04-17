#include "edit_cycles.h"
#include "ui_edit_cycles.h"
#include "communication.h"
#include <QString>

#include "numpad.h"
#include "ui_numpad.h"
#include "editline.h"

//Constructeur
edit_Cycles::edit_Cycles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Cycles)
{
    ui->setupUi(this);

    //Ajout d'un validateur dans les textbox d'édition de paramètres pour permettre
    //uniquement l'entrée de valeurs numériques
    ui->tb_Cycle1->setValidator(new QIntValidator(0,1000));
    ui->tb_Cycle2->setValidator(new QIntValidator(0,1000));
    ui->tb_Setpoint1->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Setpoint2->setValidator(new QDoubleValidator(0,1000, 2));

    connect(ui->tb_Cycle1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Cycle2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Setpoint1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Setpoint2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
}

edit_Cycles::~edit_Cycles()
{
    delete ui;
}

void edit_Cycles::onFocus(bool hasFocus)
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
