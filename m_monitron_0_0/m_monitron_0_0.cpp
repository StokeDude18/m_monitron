#include "m_monitron_0_0.h"
#include "ui_m_monitron_0_0.h"

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
#include <QPalette>

using namespace std;

//Constructeur
m_monitron_0_0::m_monitron_0_0(QWidget *parent) : QMainWindow(parent), ui(new Ui::m_monitron_0_0)
{
    ui->setupUi(this);

    //Ajout des états possibles des modules dans le combo box de contrôle d'état
    ui->cb_OpMode->addItem("Enabled");
    ui->cb_OpMode->addItem("Enabled, Alarms off");
    ui->cb_OpMode->addItem("Disabled");
    ui->cb_GOpMode->addItem("Enabled");
    ui->cb_GOpMode->addItem("Enabled, Alarms off");
    ui->cb_GOpMode->addItem("Disabled");

    //Connexion des différents textbox avec les événements de prise de focus
    connect(ui->tb_Setpoint, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_VarRate, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    connect(ui->tb_Cycle1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Cycle2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Setpoint1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_Setpoint2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    connect(ui->tb_ConvertedValue1, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_ConvertedValue2, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    connect(ui->tb_AlarmRange, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));
    connect(ui->tb_ControlRange, SIGNAL(focussed(bool)), this, SLOT(onFocus(bool)));

    connect(ui->cb_OpMode, SIGNAL(currentIndexChanged(int)),this, SLOT(cbIndexChanged(int)));
    connect(ui->cb_GOpMode, SIGNAL(currentIndexChanged(int)),this, SLOT(cbIndexChanged(int)));

    //Bloque la réception des signaux de prise de focus pour éviter des bugs au démarrage
    ui->cb_OpMode->blockSignals(true);
    ui->cb_GOpMode->blockSignals(true);

    //Ajout des textbox dans un vecteur de pointeurs de textbox
    v_textBoxArray.push_back(ui->tb_Setpoint);
    v_textBoxArray.push_back(ui->tb_VarRate);
    v_textBoxArray.push_back(ui->tb_Cycle1);
    v_textBoxArray.push_back(ui->tb_Cycle2);
    v_textBoxArray.push_back(ui->tb_ConvertedValue1);
    v_textBoxArray.push_back(ui->tb_ConvertedValue2);
    v_textBoxArray.push_back(ui->tb_Setpoint1);
    v_textBoxArray.push_back(ui->tb_Setpoint2);
    v_textBoxArray.push_back(ui->tb_AlarmRange);
    v_textBoxArray.push_back(ui->tb_ControlRange);

    //Ajout de validateurs au textbox pour empêcher l'entrée de données erronées
    ui->tb_Setpoint->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_VarRate->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Cycle1->setValidator(new QIntValidator(0,1000));
    ui->tb_Cycle2->setValidator(new QIntValidator(0,1000));
    ui->tb_ConvertedValue1->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_ConvertedValue2->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Setpoint1->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_Setpoint2->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_AlarmRange->setValidator(new QDoubleValidator(0,1000, 2));
    ui->tb_ControlRange->setValidator(new QDoubleValidator(0,1000, 2));

    nextFunction = 0;//prépare la prochaine fonction à envoyer
    nextActiveModule = 0;//initialise le prochain module à questionner
    calibModeActive = false;//Désactive le mode calibration
    comboBoxEnabled = false;//Empêche l'édition des combo box d'état système pendant l'acquisition des modules (fonction 0)
}

//Destructeur
m_monitron_0_0::~m_monitron_0_0()
{
    delete ui;
}

//Événement se produisant quand un textbox prend le focus de la fenêtre
void m_monitron_0_0::onFocus(bool hasFocus)
{
    QString qs;
    EditLine *edlObj = (EditLine *)sender();//initialise un pointeur vers le textbox qui a généré l'événement

    QPalette p;
    p.setColor(QPalette::Base, Qt::red);

    Numpad * num;

    //Détermine si le numpad doit inclure le bouton point (.)
    if(edlObj->validator()->inherits("QDoubleValidator"))
        num = new Numpad(true);
    else
        num = new Numpad(false);

    if(hasFocus == true)//Si l'événement de focus était un "focus in"
    {
        num->exec();//Affiche le numpad

        if(num->result() == QDialog::Accepted)//Si le bouton OK du numpad a généré la fermeture de celui-ci
        {
            /*Si la valeur entrée est différente de la valeur déjà présente dans le textbox,
              met le champ concerné et le bouton apply changes en rouge*/
            if(edlObj->text() != num->ui->le_Entry->text())
            {
                edlObj->setPalette(p);
                p.setColor(QPalette::Button, Qt::red);
                ui->b_Apply_Changes->setPalette(p);
            }

            /*Si le champ sélectionné est un champ de calibration, la valeur
              en mV associée à la valeur entrée sera la valeur (en mV) courante*/
            if(edlObj == ui->tb_ConvertedValue1)
            {
                ui->l_RawValueP1_Current->setText(ui->l_Lecture_mV_Current->text());
            }
            else if(edlObj == ui->tb_ConvertedValue2)
            {
                ui->l_RawValueP2_Current->setText(ui->l_Lecture_mV_Current->text());
            }

            edlObj->setText(num->ui->le_Entry->text());//Copie le texte du champ du numpad dans le textbox
        }
        delete num;//détruit l'objet numpad
        ui->b_Apply_Changes->setFocus();//Donne le focus de la fenêtre au bouton Apply changes
    }
}

//Méthode servant à afficher des nouveaux paramètres dans l'interface usager
void m_monitron_0_0::printParams(module* mod, uint8_t fonction)
{
    char module_type[20];
    QString qs;

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

    //Affiche les nouveaux paramètres dans l'interface
    if(fonction > 0)
    {
        qs.sprintf("%.2f", mod->Lecture);
        ui->l_current_Reading->setText(qs);


        if(fonction == 1 && !calibModeActive)
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
            ui->l_RawValueP1_Current->setText(qs);

            qs.sprintf("%.2f", mod->Calib.converted_P1);
            ui->tb_ConvertedValue1->setText(qs);

            qs.sprintf("%.2f", mod->Calib.raw_P2);
            ui->l_RawValueP2_Current->setText(qs);

            qs.sprintf("%.2f", mod->Calib.converted_P2);
            ui->tb_ConvertedValue2->setText(qs);

            qs.sprintf("%.2f", mod->Reading_mV);
            ui->l_Lecture_mV_Current->setText(qs);

            qs.sprintf("%.2f", mod->Control.Control_Range);
            ui->tb_ControlRange->setText(qs);

            qs.sprintf("%.2f", mod->Control.Alarm_Range);
            ui->tb_AlarmRange->setText(qs);

            ui->cb_OpMode->setCurrentIndex(mod->Control.OP_Mode);

            ui->cb_GOpMode->setCurrentIndex(mod->Control.Global_OP_Mode);

            m_newParams = *mod;
        }

        else if(calibModeActive)//Si procédure de calibration en cours
        {
            //Ne rafraîchit seulement que le champ de la lecture en mV
            qs.sprintf("%.2f", mod->Reading_mV);
            ui->l_Lecture_mV_Current->setText(qs);
        }
    }
}

//Méthode publique servant à dicter au processus principal la prochaîne requête au module d'acquisition
uint8_t m_monitron_0_0::getNextFunction()
{
    //Si le module envoie les nouveaux paramètres au module, termine toute éventuelle séquence de calibration en cours
    if(nextFunction == 3)
        calibModeActive = false;
    //Si calibration en cours, et que la prochaine requête n'est pas un envoi de paramètres, demande une fonction 1
    else if(calibModeActive)
        nextFunction = 1;
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
    float2bytes  u_calib1_raw;
    float2bytes  u_calib2_raw;
    float2bytes  u_calib1_converted;
    float2bytes  u_calib2_converted;
    float2bytes  u_control_range;
    float2bytes  u_alarm_range;

    //Copie le contenu des paramètres dans le buffer d'envoi
    u_setpoint.f = m_newParams.Setpoint;    
    sendBuffer[t3_Setpoint1] = u_setpoint.b[0];
    sendBuffer[t3_Setpoint2] = u_setpoint.b[1];
    sendBuffer[t3_Setpoint3] = u_setpoint.b[2];
    sendBuffer[t3_Setpoint4] = u_setpoint.b[3];

    u_varRate.f = m_newParams.Var_Rate;
    sendBuffer[t3_VarRate1]  = u_varRate.b[0];
    sendBuffer[t3_VarRate2]  = u_varRate.b[1];
    sendBuffer[t3_VarRate3]  = u_varRate.b[2];
    sendBuffer[t3_VarRate4]  = u_varRate.b[3];

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

    u_calib1_raw.f = m_newParams.Calib.raw_P1;
    sendBuffer[t3_CalibRaw1_1] = u_calib1_raw.b[0];
    sendBuffer[t3_CalibRaw1_2] = u_calib1_raw.b[1];
    sendBuffer[t3_CalibRaw1_3] = u_calib1_raw.b[2];
    sendBuffer[t3_CalibRaw1_4] = u_calib1_raw.b[3];

    u_calib1_converted.f = m_newParams.Calib.converted_P1;
    sendBuffer[t3_CalibConverted1_1] = u_calib1_converted.b[0];
    sendBuffer[t3_CalibConverted1_2] = u_calib1_converted.b[1];
    sendBuffer[t3_CalibConverted1_3] = u_calib1_converted.b[2];
    sendBuffer[t3_CalibConverted1_4] = u_calib1_converted.b[3];

    u_calib2_raw.f = m_newParams.Calib.raw_P2;
    sendBuffer[t3_CalibRaw2_1] = u_calib2_raw.b[0];
    sendBuffer[t3_CalibRaw2_2] = u_calib2_raw.b[1];
    sendBuffer[t3_CalibRaw2_3] = u_calib2_raw.b[2];
    sendBuffer[t3_CalibRaw2_4] = u_calib2_raw.b[3];

    u_calib2_converted.f = m_newParams.Calib.converted_P2;
    sendBuffer[t3_CalibConverted2_1] = u_calib2_converted.b[0];
    sendBuffer[t3_CalibConverted2_2] = u_calib2_converted.b[1];
    sendBuffer[t3_CalibConverted2_3] = u_calib2_converted.b[2];
    sendBuffer[t3_CalibConverted2_4] = u_calib2_converted.b[3];


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
}

//Événement au clic du bouton Apply changes
void m_monitron_0_0::on_b_Apply_Changes_clicked()
{
    QPalette p;
    p.setColor(QPalette::Base, Qt::white);
    p.setColor(QPalette::Button, Qt::white);

    //Rassemble tous les paramètres textuels et les convertit dans l'objet m_newParams
    m_newParams.Setpoint = ui->tb_Setpoint->text().toDouble();
    m_newParams.Var_Rate = ui->tb_VarRate->text().toDouble();
    m_newParams.Cycles.Cycle1 = ui->tb_Cycle1->text().toInt();
    m_newParams.Cycles.Cycle2 = ui->tb_Cycle2->text().toInt();

    m_newParams.Calib.raw_P1 = ui->l_RawValueP1_Current->text().toDouble();
    m_newParams.Calib.converted_P1 = ui->tb_ConvertedValue1->text().toDouble();
    m_newParams.Calib.raw_P2 = ui->l_RawValueP2_Current->text().toDouble();
    m_newParams.Calib.converted_P2 = ui->tb_ConvertedValue2->text().toDouble();

    m_newParams.Cycles.Setpoint1 = ui->tb_Setpoint1->text().toDouble();
    m_newParams.Cycles.Setpoint2 = ui->tb_Setpoint2->text().toDouble();
    m_newParams.Control.Alarm_Range = ui->tb_AlarmRange->text().toDouble();
    m_newParams.Control.Control_Range = ui->tb_ControlRange->text().toDouble();
    m_newParams.Control.OP_Mode = ui->cb_OpMode->currentIndex();

    //Remet tous les textbox dans leur couleur d'origine
    for(auto &it_el : v_textBoxArray)
        it_el->setPalette(p);

    //Remet le bouton Apply changes et les combo box d'édition à leur couleur normale
    ui->b_Apply_Changes->setPalette(p);
    ui->cb_OpMode->setPalette(p);
    ui->cb_GOpMode->setPalette(p);

    //Si une procédure de calibration était en cours
    if(calibModeActive)
    {
        ui->b_Calibration->setEnabled(true);//Réactive le bouton Calibration
        //Désactive les textbox de calibration
        ui->tb_ConvertedValue1->setEnabled(false);
        ui->tb_ConvertedValue2->setEnabled(false);
        ui->l_UserMessage->setText("");//Enlève le texte d'avis à l'usager qui est présent en mode calibration
    }
    //Spécifie au programme que la prochaine trame d'envoi sera une trame d'édition de paramètres
    setNextFunction(3);
}


//Méthode ajoutant les numéros d'identification des modules dans un combo box de la fenêtre principale
//pour la sélection du module courant
void m_monitron_0_0::addModuleToMenu(uint32_t modID, uint8_t type, uint8_t position)
{
    QString qs;
    QString s;
    switch(type)
    {
    case 0:
        s = "Temp.";
        break;
    case 1:
        s = "Ox.";
        break;
    case 2:
        s = "Sal.";
        break;
    case 3:
        s = "PH";
        break;
    case 4:
        s = "Flow";
        break;
    case 5:
        s = "Level";
        break;
    }

    qs.sprintf("%d Pos. %d Type: ", modID, position);
    ui->cb_Module_Select->addItem(qs + s);//Ajout du ID du module.
}

//Quand l'index du sélecteur de module change, modifie le module courant pour la prochaine requête
void m_monitron_0_0::on_cb_Module_Select_currentIndexChanged(int index)
{
    setNextActiveModule(index);
}

/*Méthode servant à indiquer au processus principal (main)
  le prochain module avec lequel il va interragir*/
uint8_t m_monitron_0_0::getNextActiveModule()
{
    return nextActiveModule;
}

//Méthode permettant de définir le prochain module actif
void m_monitron_0_0::setNextActiveModule(uint8_t modIndex)
{
    nextActiveModule = modIndex;
}

//Méthode permettant de tomber en mode calibration suite au clic du bouton Calibration
void m_monitron_0_0::on_b_Calibration_clicked()
{
    QPalette p;
    p.setColor(QPalette::WindowText, Qt::red);

    //Si on n'est pas déjà en mode calibration
    if(calibModeActive == false)
    {
        calibModeActive = true;//Met le flag du mode calib à true
        //Active les textbox de calibration et désactive le bouton Calibration
        ui->b_Calibration->setEnabled(false);
        ui->tb_ConvertedValue1->setEnabled(true);
        ui->tb_ConvertedValue2->setEnabled(true);
        //Affiche un message à l'usager pour lui dire comment quitter le mode Calibration
        ui->l_UserMessage->setText("You need to apply the changes to quit calibration mode.");
        ui->l_UserMessage->setPalette(p);//Met le texte en rouge
    }
}

/*Méthode appelée quand un des combo box de changement
  d'état (Operating mode et G_Operating mode) est modifié*/
void m_monitron_0_0::cbIndexChanged(int index)
{
    QComboBox *cbObj = (QComboBox*)sender();//Initialise un pointeur vers le combo box générant l'événement
    QPalette p;
    p.setColor(QPalette::Button, Qt::red);
    cbObj->setPalette(p);//Met le combo box en rouge
    ui->b_Apply_Changes->setPalette(p);//Met le bouton Apply changes en rouge
}

/*Méthode appelée par le processus principal (main) pour réactiver
  la réception des événements index changed des combo box de cangement d'état*/
void m_monitron_0_0::enableComboBox()
{
    //Débloque l'entrée des signaux sur les combo box
    ui->cb_OpMode->blockSignals(false);
    ui->cb_GOpMode->blockSignals(false);
    comboBoxEnabled = true;
}

void m_monitron_0_0::on_b_exit_clicked()
{
    QApplication::quit();
}
