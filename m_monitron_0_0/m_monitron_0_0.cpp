#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"
#include "edit_calibration.h"
#include "ui_edit_calibration.h"

#include "communication.h"
#include "editline.h"
#include "numpad.h"
#include "ui_numpad.h"

#include <QtWidgets>
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <exception>
#include <QtGui>
#include <QString>
#include <vector>

using namespace std;

//Constructeur
m_monitron_0_0::m_monitron_0_0(QWidget *parent) : QMainWindow(parent), ui(new Ui::m_monitron_0_0)
{
    ui->setupUi(this);
    ui->cb_OpMode->addItem("Enabled");
    ui->cb_OpMode->addItem("Disabled");
    ui->cb_GOpMode->addItem("Enabled");
    ui->cb_GOpMode->addItem("Disabled");
    connect(ui->tb_Setpoint, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_VarRate, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    connect(ui->tb_Cycle1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Cycle2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Setpoint1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Setpoint2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    connect(ui->tb_AlarmRange, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_ControlRange, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    v_textBoxArray.push_back(ui->tb_Setpoint);
    v_textBoxArray.push_back(ui->tb_VarRate);
    v_textBoxArray.push_back(ui->tb_Cycle1);
    v_textBoxArray.push_back(ui->tb_Cycle2);
    v_textBoxArray.push_back(ui->tb_Setpoint1);
    v_textBoxArray.push_back(ui->tb_Setpoint2);
    v_textBoxArray.push_back(ui->tb_AlarmRange);
    v_textBoxArray.push_back(ui->tb_ControlRange);

    ui->tb_Setpoint->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_VarRate->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Cycle1->setValidator(new QIntValidator(0,1000));
    ui->tb_Cycle2->setValidator(new QIntValidator(0,1000));
    ui->tb_Setpoint1->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Setpoint2->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_AlarmRange->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_ControlRange->setValidator(new QDoubleValidator(0,1000, 2));

    nextFunction = 0;//prépare la prochaine fonction à envoyer
    nextActiveModule = 0;
}

m_monitron_0_0::~m_monitron_0_0()
{
    delete ui;
}

void m_monitron_0_0::onFocus(bool hasFocus)
{
    EditLine *edlObj = (EditLine *)sender();
    QPalette p;
    p.setColor(QPalette::Base, Qt::red);
    Numpad * num;
    if(edlObj->validator()->inherits("QDoubleValidator"))
        num = new Numpad(true);
    else
        num = new Numpad(false);

    if(hasFocus == true)
    {
        num->exec();
        if(num->result() == QDialog::Accepted)
        {
            if(edlObj->text() != num->ui->le_Entry->text())
                edlObj->setPalette(p);
            edlObj->setText(num->ui->le_Entry->text());
        }
        delete num;
        ui->b_Apply_Changes->setFocus();
    }
}

//Méthode servant à afficher des nouveaux paramètres dans l'interface usager
void m_monitron_0_0::printParams(module* mod, uint8_t fonction)
{
    //string qs = "Device ID: " + to_string(mod->ID) + "  Position: " + to_string((char)mod->Position) + "  Type: " + to_string((char)mod->Type);
    char module_type[20];
    QString qs;// = QString("Device ID: %1  Position: %2  Type: %3").arg(to_string(mod->ID), to_string((char)mod->Position), to_string((char)mod->Type));

    //Détermine le texte à afficher dans la barre d'état en fonction du type de capteur
    switch(mod->Type)
    {
    case 0:
        sprintf(module_type, "Temperature");

        break;
    case 1:
        sprintf(module_type, "Oxygene");
        //module_type = "Oxygene";
        break;
    case 2:
        sprintf(module_type, "Salinite");
        //module_type = "Salinite";
        break;
    case 3:
        sprintf(module_type, "PH");
        //module_type = "PH";
        break;
    case 4:
        sprintf(module_type, "Debit");
        //module_type = "Debit";
        break;
    case 5:
        sprintf(module_type, "Niveau");
        //module_type = "Niveau";

    }

    //Affiche la barre d'état
    qs.sprintf("Device ID: %u  Position: %d  Type: %s   G. Op. Mode: %s", mod->ID, mod->Position, module_type, (mod->Control.Global_OP_Mode == 0) ? "Disabled" : "Enabled");
    ui->sbar_Device_Informations->showMessage(qs);

    if(fonction > 0)//Les nouveaux paramètres dans l'interface
    {
        qs.sprintf("%.2f", mod->Lecture);
        ui->l_current_Reading->setText(qs);


        if(fonction == 1)
        {
            qs.sprintf("%.2f", mod->Setpoint);
            ui->tb_Setpoint->setText(qs);
            qs.sprintf("%.2f", mod->Var_Rate);
            ui->tb_VarRate->setText(qs);

            qs.sprintf("%u", mod->Cycles.Cycle1);
            ui->tb_Cycle1->setText(qs);

            qs.sprintf("%u", mod->Cycles.Cycle2);
            ui->tb_Cycle2->setText(qs);

            qs.sprintf("%.2f", mod->Cycles.Setpoint1);
            ui->tb_Setpoint1->setText(qs);

            qs.sprintf("%.2f", mod->Cycles.Setpoint2);
            ui->tb_Setpoint2->setText(qs);

            ui->l_Cycle_Mode_Current_State->setText((mod->Cycles.Cycle_Mode_State == 1) ? "ON" : "OFF");

            qs.sprintf("%.2f", mod->Calib.raw_P1);
            ui->l_Current_P1_raw->setText(qs);

            qs.sprintf("%.2f", mod->Calib.converted_P1);
            ui->l_Current_P1_converted->setText(qs);

            qs.sprintf("%.2f", mod->Calib.raw_P2);
            ui->l_Current_P2_raw->setText(qs);

            qs.sprintf("%.2f", mod->Calib.converted_P2);
            ui->l_Current_P2_converted->setText(qs);

            qs.sprintf("%.2f", mod->Reading_mV);
            ui->l_Lecture_mV_Current->setText(qs);

            qs.sprintf("%.2f", mod->Control.Control_Range);
            ui->tb_ControlRange->setText(qs);

            qs.sprintf("%.2f", mod->Control.Alarm_Range);
            ui->tb_AlarmRange->setText(qs);

            ui->cb_OpMode->setCurrentIndex((mod->Control.OP_Mode == 1) ? 0: 1);

            ui->cb_GOpMode->setCurrentIndex((mod->Control.Global_OP_Mode == 1) ? 0: 1);

            m_newParams = *mod;
        }
    }
}

//Méthode publique servant à évaluer dicter au processus principal la prochaîne requête au module d'acquisition
uint8_t m_monitron_0_0::getNextFunction()
{
    return nextFunction;
}

//Méthode publique permettant au processus principal de dicter la prochaine fonction à envoyer
void m_monitron_0_0::setNextFunction(uint8_t function)
{
    if(function >= 0 && function <= 4)
        nextFunction = function;
}

//Méthode utilisée pour rassembler les nouveux paramètres avant de les envoyer au MBED
void m_monitron_0_0::getNewParams(module *objNewParams)
{
    objNewParams = &m_newParams;
}

//Méthode utilisée pour bâtir une trame d'édition de paramètres
void m_monitron_0_0::buildF3Frame(uint8_t* sendBuffer)
{
    //Unions servant à diviser les données en octets pour l'envoi sur le port série
    float2bytes  u_setpoint;
    float2bytes  u_varRate;
    int2bytes    u_cycle1;
    int2bytes    u_cycle2;
    float2bytes  u_cycle1_setpoint;
    float2bytes  u_cycle2_setpoint;
    /*float2bytes  u_calib1_raw;
    float2bytes  u_calib2_raw;
    float2bytes  u_calib1_converted;
    float2bytes  u_calib2_converted;*/
    float2bytes  u_control_range;
    float2bytes  u_alarm_range;

    u_setpoint.f = m_newParams.Setpoint;
    printf("Setpoint: %f\n", m_newParams.Setpoint);
    sendBuffer[t3_Setpoint1] = u_setpoint.b[0];
    sendBuffer[t3_Setpoint2] = u_setpoint.b[1];
    sendBuffer[t3_Setpoint3] = u_setpoint.b[2];
    sendBuffer[t3_Setpoint4] = u_setpoint.b[3];

    u_varRate.f = m_newParams.Var_Rate;
    sendBuffer[t3_VarRate1]  = u_varRate.b[0];
    sendBuffer[t3_VarRate2]  = u_varRate.b[1];
    sendBuffer[t3_VarRate3]  = u_varRate.b[2];
    sendBuffer[t3_VarRate4]  = u_varRate.b[3];
    printf("Var Rate::: %f", u_varRate.f);

    u_cycle1.i = m_newParams.Cycles.Cycle1;
    sendBuffer[t3_Cycle1_1]  = u_cycle1.b[0];
    sendBuffer[t3_Cycle1_2]  = u_cycle1.b[1];

    u_cycle2.i = m_newParams.Cycles.Cycle2;
    sendBuffer[t3_Cycle2_1]  = u_cycle2.b[0];
    sendBuffer[t3_Cycle2_2]  = u_cycle2.b[1];

    u_cycle1_setpoint.f = m_newParams.Cycles.Setpoint1;
    sendBuffer[t3_Setpoint1_1]  = u_cycle1_setpoint.b[0];
    sendBuffer[t3_Setpoint1_2]  = u_cycle1_setpoint.b[1];
    sendBuffer[t3_Setpoint1_3]  = u_cycle1_setpoint.b[2];
    sendBuffer[t3_Setpoint1_4]  = u_cycle1_setpoint.b[3];

    u_cycle2_setpoint.f = m_newParams.Cycles.Setpoint2;
    sendBuffer[t3_Setpoint2_1]  = u_cycle2_setpoint.b[0];
    sendBuffer[t3_Setpoint2_2]  = u_cycle2_setpoint.b[1];
    sendBuffer[t3_Setpoint2_3]  = u_cycle2_setpoint.b[2];
    sendBuffer[t3_Setpoint2_4]  = u_cycle2_setpoint.b[3];

    /*u_calib1_raw.f = m_newParams.Calib.raw_P1;
    u_calib2_raw.f = m_newParams.Calib.raw_P2;
    u_calib1_converted.f = m_newParams.Calib.converted_P1;
    u_calib2_converted.f = m_newParams.Calib.converted_P2;*/

    u_control_range.f = m_newParams.Control.Control_Range;
    sendBuffer[t3_ControlRange1] = u_control_range.b[0];
    sendBuffer[t3_ControlRange2] = u_control_range.b[1];
    sendBuffer[t3_ControlRange3] = u_control_range.b[2];
    sendBuffer[t3_ControlRange4] = u_control_range.b[3];

    u_alarm_range.f = m_newParams.Control.Alarm_Range;
    sendBuffer[t3_AlarmRange1] = u_alarm_range.b[0];
    sendBuffer[t3_AlarmRange2] = u_alarm_range.b[1];
    sendBuffer[t3_AlarmRange3] = u_alarm_range.b[2];
    sendBuffer[t3_AlarmRange4] = u_alarm_range.b[3];

    sendBuffer[t3_OP_Mode] = m_newParams.Control.OP_Mode;

    printf("F3\n");
}

//Événement au clic du bouton Apply changes
void m_monitron_0_0::on_b_Apply_Changes_clicked()
{
    QPalette p;
    p.setColor(QPalette::Base, Qt::white);
    m_newParams.Setpoint = ui->tb_Setpoint->text().toDouble();
    m_newParams.Var_Rate = ui->tb_VarRate->text().toDouble();
    m_newParams.Cycles.Cycle1 = ui->tb_Cycle1->text().toInt();
    m_newParams.Cycles.Cycle2 = ui->tb_Cycle2->text().toInt();
    m_newParams.Cycles.Setpoint1 = ui->tb_Setpoint1->text().toDouble();
    m_newParams.Cycles.Setpoint2 = ui->tb_Setpoint2->text().toDouble();
    m_newParams.Control.Alarm_Range = ui->tb_AlarmRange->text().toDouble();
    m_newParams.Control.Control_Range = ui->tb_ControlRange->text().toDouble();

    for(auto &it_el : v_textBoxArray)
        it_el->setPalette(p);

    //Spécifie au programme que la prochaine trame d'envoi sera une trame d'édition de paramètres
    nextFunction = 3;
}


//Méthode ajoutant les numéros d'identification des modules dans un combo box de la fenêtre principale
//pour la sélection du module courant
void m_monitron_0_0::addModuleToMenu(uint32_t modID)
{
    QString qs;
    qs.sprintf("%d", modID);
    ui->cb_Module_Select->addItem(qs);//Ajout du ID du module.
}

void m_monitron_0_0::on_cb_Module_Select_currentIndexChanged(int index)
{
    setNextActiveModule(index);
}

uint8_t m_monitron_0_0::getNextActiveModule()
{
    return nextActiveModule;
}

void m_monitron_0_0::setNextActiveModule(uint8_t modIndex)
{
    nextActiveModule = modIndex;
}
