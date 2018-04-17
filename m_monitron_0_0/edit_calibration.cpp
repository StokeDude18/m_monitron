#include "edit_calibration.h"
#include "ui_edit_calibration.h"
#include <QLineEdit>
#include "communication.h"
#include <QString>

#include "numpad.h"
#include "ui_numpad.h"
#include "editline.h"

//Constructeur
edit_Calibration::edit_Calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_Calibration)
{    
    ui->setupUi(this);

    //Ajout d'un validateur dans les textbox d'édition de paramètres pour permettre
    //uniquement l'entrée de valeurs numériques
    ui->tb_P1_mV->setValidator(new QDoubleValidator(0, 5000, 2, this));
    ui->tb_P1_Convert_Unit->setValidator(new QDoubleValidator(0, 10000, 3, this));
    ui->tb_P2_mV->setValidator(new QDoubleValidator(0, 5000, 2, this));
    ui->tb_P2_Convert_Unit->setValidator(new QDoubleValidator(0, 10000, 3, this));

    connect(ui->tb_P1_mV, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_P1_Convert_Unit, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_P2_mV, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_P2_Convert_Unit, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
}

edit_Calibration::~edit_Calibration()
{
    delete ui;
}

void edit_Calibration::onFocus(bool hasFocus)
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
