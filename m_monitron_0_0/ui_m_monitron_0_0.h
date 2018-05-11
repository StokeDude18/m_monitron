/********************************************************************************
** Form generated from reading UI file 'm_monitron_0_0.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_MONITRON_0_0_H
#define UI_M_MONITRON_0_0_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "editline.h"

QT_BEGIN_NAMESPACE

class Ui_m_monitron_0_0
{
public:
    QWidget *centralWidget;
    QTabWidget *cb_O_Mode;
    QWidget *t_Lecture;
    QLabel *l_Lecture;
    QLabel *l_Setpoint;
    QLabel *l_Taux_Var;
    QLabel *l_current_Reading;
    EditLine *tb_Setpoint;
    EditLine *tb_VarRate;
    QWidget *t_Cycles;
    QLabel *l_Cycle_Mode_State;
    QLabel *l_Setpoint_Cycle_1;
    QLabel *l_Cycle2;
    QLabel *l_Setpoint_Cycle_2;
    QLabel *l_Cycle1;
    QLabel *l_Cycle_Mode_Current_State;
    EditLine *tb_Cycle1;
    EditLine *tb_Cycle2;
    EditLine *tb_Setpoint1;
    EditLine *tb_Setpoint2;
    QWidget *t_Calibration;
    QLabel *l_Lecture_mV;
    QPushButton *b_Calibration;
    QLabel *l_Val_Convertie;
    QLabel *l_Lecture_mV_Current;
    QLabel *l_Lecture_Converted_Current;
    EditLine *tb_ConvertedValue1;
    QLabel *l_P1_Convert_Unit;
    QLabel *l_P2_Convert_Unit;
    EditLine *tb_ConvertedValue2;
    QLabel *l_RawValueP1;
    QLabel *l_RawValueP2;
    QLabel *l_RawValueP1_Current;
    QLabel *l_RawValueP2_Current;
    QWidget *t_Control_OP;
    QLabel *l_Control_Range;
    QLabel *l_Alarm_Range;
    QLabel *l_OP_Mode;
    QLabel *l_GOP_Mode;
    EditLine *tb_ControlRange;
    EditLine *tb_AlarmRange;
    QComboBox *cb_OpMode;
    QComboBox *cb_GOpMode;
    QWidget *t_Graph;
    QPushButton *b_Apply_Changes;
    QComboBox *cb_Module_Select;
    QLabel *l_UserMessage;
    QMenuBar *menuBar;
    QStatusBar *sbar_Device_Informations;

    void setupUi(QMainWindow *m_monitron_0_0)
    {
        if (m_monitron_0_0->objectName().isEmpty())
            m_monitron_0_0->setObjectName(QStringLiteral("m_monitron_0_0"));
        m_monitron_0_0->resize(800, 480);
        QFont font;
        font.setPointSize(20);
        m_monitron_0_0->setFont(font);
        m_monitron_0_0->setAutoFillBackground(false);
        centralWidget = new QWidget(m_monitron_0_0);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cb_O_Mode = new QTabWidget(centralWidget);
        cb_O_Mode->setObjectName(QStringLiteral("cb_O_Mode"));
        cb_O_Mode->setGeometry(QRect(25, 15, 781, 351));
        QFont font1;
        font1.setPointSize(16);
        cb_O_Mode->setFont(font1);
        t_Lecture = new QWidget();
        t_Lecture->setObjectName(QStringLiteral("t_Lecture"));
        l_Lecture = new QLabel(t_Lecture);
        l_Lecture->setObjectName(QStringLiteral("l_Lecture"));
        l_Lecture->setGeometry(QRect(20, 30, 186, 46));
        QFont font2;
        font2.setPointSize(30);
        l_Lecture->setFont(font2);
        l_Setpoint = new QLabel(t_Lecture);
        l_Setpoint->setObjectName(QStringLiteral("l_Setpoint"));
        l_Setpoint->setGeometry(QRect(20, 105, 176, 41));
        l_Setpoint->setFont(font2);
        l_Taux_Var = new QLabel(t_Lecture);
        l_Taux_Var->setObjectName(QStringLiteral("l_Taux_Var"));
        l_Taux_Var->setGeometry(QRect(20, 175, 286, 46));
        l_Taux_Var->setFont(font2);
        l_current_Reading = new QLabel(t_Lecture);
        l_current_Reading->setObjectName(QStringLiteral("l_current_Reading"));
        l_current_Reading->setGeometry(QRect(315, 40, 176, 36));
        QFont font3;
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        l_current_Reading->setFont(font3);
        tb_Setpoint = new EditLine(t_Lecture);
        tb_Setpoint->setObjectName(QStringLiteral("tb_Setpoint"));
        tb_Setpoint->setEnabled(true);
        tb_Setpoint->setGeometry(QRect(310, 105, 186, 41));
        tb_Setpoint->setFont(font2);
        tb_VarRate = new EditLine(t_Lecture);
        tb_VarRate->setObjectName(QStringLiteral("tb_VarRate"));
        tb_VarRate->setEnabled(true);
        tb_VarRate->setGeometry(QRect(310, 180, 186, 41));
        tb_VarRate->setFont(font2);
        cb_O_Mode->addTab(t_Lecture, QString());
        t_Cycles = new QWidget();
        t_Cycles->setObjectName(QStringLiteral("t_Cycles"));
        l_Cycle_Mode_State = new QLabel(t_Cycles);
        l_Cycle_Mode_State->setObjectName(QStringLiteral("l_Cycle_Mode_State"));
        l_Cycle_Mode_State->setGeometry(QRect(20, 25, 391, 46));
        l_Cycle_Mode_State->setFont(font2);
        l_Setpoint_Cycle_1 = new QLabel(t_Cycles);
        l_Setpoint_Cycle_1->setObjectName(QStringLiteral("l_Setpoint_Cycle_1"));
        l_Setpoint_Cycle_1->setGeometry(QRect(250, 110, 176, 36));
        QFont font4;
        font4.setPointSize(24);
        l_Setpoint_Cycle_1->setFont(font4);
        l_Cycle2 = new QLabel(t_Cycles);
        l_Cycle2->setObjectName(QStringLiteral("l_Cycle2"));
        l_Cycle2->setGeometry(QRect(20, 190, 131, 36));
        l_Cycle2->setFont(font4);
        l_Setpoint_Cycle_2 = new QLabel(t_Cycles);
        l_Setpoint_Cycle_2->setObjectName(QStringLiteral("l_Setpoint_Cycle_2"));
        l_Setpoint_Cycle_2->setGeometry(QRect(250, 190, 176, 36));
        l_Setpoint_Cycle_2->setFont(font4);
        l_Cycle1 = new QLabel(t_Cycles);
        l_Cycle1->setObjectName(QStringLiteral("l_Cycle1"));
        l_Cycle1->setGeometry(QRect(20, 110, 131, 36));
        l_Cycle1->setFont(font4);
        l_Cycle_Mode_Current_State = new QLabel(t_Cycles);
        l_Cycle_Mode_Current_State->setObjectName(QStringLiteral("l_Cycle_Mode_Current_State"));
        l_Cycle_Mode_Current_State->setGeometry(QRect(420, 30, 86, 41));
        l_Cycle_Mode_Current_State->setFont(font3);
        tb_Cycle1 = new EditLine(t_Cycles);
        tb_Cycle1->setObjectName(QStringLiteral("tb_Cycle1"));
        tb_Cycle1->setGeometry(QRect(155, 110, 81, 36));
        tb_Cycle1->setFont(font4);
        tb_Cycle2 = new EditLine(t_Cycles);
        tb_Cycle2->setObjectName(QStringLiteral("tb_Cycle2"));
        tb_Cycle2->setGeometry(QRect(155, 190, 81, 36));
        tb_Cycle2->setFont(font4);
        tb_Setpoint1 = new EditLine(t_Cycles);
        tb_Setpoint1->setObjectName(QStringLiteral("tb_Setpoint1"));
        tb_Setpoint1->setGeometry(QRect(430, 110, 156, 36));
        tb_Setpoint1->setFont(font4);
        tb_Setpoint2 = new EditLine(t_Cycles);
        tb_Setpoint2->setObjectName(QStringLiteral("tb_Setpoint2"));
        tb_Setpoint2->setGeometry(QRect(430, 190, 156, 36));
        tb_Setpoint2->setFont(font4);
        cb_O_Mode->addTab(t_Cycles, QString());
        t_Calibration = new QWidget();
        t_Calibration->setObjectName(QStringLiteral("t_Calibration"));
        l_Lecture_mV = new QLabel(t_Calibration);
        l_Lecture_mV->setObjectName(QStringLiteral("l_Lecture_mV"));
        l_Lecture_mV->setGeometry(QRect(20, 20, 241, 36));
        l_Lecture_mV->setFont(font4);
        b_Calibration = new QPushButton(t_Calibration);
        b_Calibration->setObjectName(QStringLiteral("b_Calibration"));
        b_Calibration->setGeometry(QRect(630, 10, 141, 66));
        l_Val_Convertie = new QLabel(t_Calibration);
        l_Val_Convertie->setObjectName(QStringLiteral("l_Val_Convertie"));
        l_Val_Convertie->setGeometry(QRect(20, 75, 281, 31));
        QFont font5;
        font5.setPointSize(24);
        font5.setItalic(false);
        l_Val_Convertie->setFont(font5);
        l_Lecture_mV_Current = new QLabel(t_Calibration);
        l_Lecture_mV_Current->setObjectName(QStringLiteral("l_Lecture_mV_Current"));
        l_Lecture_mV_Current->setGeometry(QRect(310, 20, 171, 31));
        QFont font6;
        font6.setPointSize(22);
        font6.setBold(true);
        font6.setWeight(75);
        l_Lecture_mV_Current->setFont(font6);
        l_Lecture_Converted_Current = new QLabel(t_Calibration);
        l_Lecture_Converted_Current->setObjectName(QStringLiteral("l_Lecture_Converted_Current"));
        l_Lecture_Converted_Current->setGeometry(QRect(310, 80, 156, 26));
        l_Lecture_Converted_Current->setFont(font6);
        tb_ConvertedValue1 = new EditLine(t_Calibration);
        tb_ConvertedValue1->setObjectName(QStringLiteral("tb_ConvertedValue1"));
        tb_ConvertedValue1->setEnabled(false);
        tb_ConvertedValue1->setGeometry(QRect(300, 130, 106, 31));
        tb_ConvertedValue1->setFont(font);
        l_P1_Convert_Unit = new QLabel(t_Calibration);
        l_P1_Convert_Unit->setObjectName(QStringLiteral("l_P1_Convert_Unit"));
        l_P1_Convert_Unit->setGeometry(QRect(20, 130, 271, 26));
        QFont font7;
        font7.setPointSize(20);
        font7.setBold(false);
        font7.setWeight(50);
        l_P1_Convert_Unit->setFont(font7);
        l_P2_Convert_Unit = new QLabel(t_Calibration);
        l_P2_Convert_Unit->setObjectName(QStringLiteral("l_P2_Convert_Unit"));
        l_P2_Convert_Unit->setGeometry(QRect(20, 180, 271, 26));
        l_P2_Convert_Unit->setFont(font7);
        tb_ConvertedValue2 = new EditLine(t_Calibration);
        tb_ConvertedValue2->setObjectName(QStringLiteral("tb_ConvertedValue2"));
        tb_ConvertedValue2->setEnabled(false);
        tb_ConvertedValue2->setGeometry(QRect(300, 180, 106, 31));
        tb_ConvertedValue2->setFont(font);
        l_RawValueP1 = new QLabel(t_Calibration);
        l_RawValueP1->setObjectName(QStringLiteral("l_RawValueP1"));
        l_RawValueP1->setGeometry(QRect(420, 130, 201, 26));
        l_RawValueP1->setFont(font7);
        l_RawValueP2 = new QLabel(t_Calibration);
        l_RawValueP2->setObjectName(QStringLiteral("l_RawValueP2"));
        l_RawValueP2->setGeometry(QRect(420, 185, 196, 26));
        l_RawValueP2->setFont(font7);
        l_RawValueP1_Current = new QLabel(t_Calibration);
        l_RawValueP1_Current->setObjectName(QStringLiteral("l_RawValueP1_Current"));
        l_RawValueP1_Current->setGeometry(QRect(620, 130, 141, 26));
        QFont font8;
        font8.setPointSize(20);
        font8.setBold(true);
        font8.setWeight(75);
        l_RawValueP1_Current->setFont(font8);
        l_RawValueP2_Current = new QLabel(t_Calibration);
        l_RawValueP2_Current->setObjectName(QStringLiteral("l_RawValueP2_Current"));
        l_RawValueP2_Current->setGeometry(QRect(620, 185, 141, 26));
        l_RawValueP2_Current->setFont(font8);
        cb_O_Mode->addTab(t_Calibration, QString());
        t_Control_OP = new QWidget();
        t_Control_OP->setObjectName(QStringLiteral("t_Control_OP"));
        l_Control_Range = new QLabel(t_Control_OP);
        l_Control_Range->setObjectName(QStringLiteral("l_Control_Range"));
        l_Control_Range->setGeometry(QRect(20, 20, 176, 31));
        QFont font9;
        font9.setPointSize(18);
        font9.setItalic(false);
        l_Control_Range->setFont(font9);
        l_Alarm_Range = new QLabel(t_Control_OP);
        l_Alarm_Range->setObjectName(QStringLiteral("l_Alarm_Range"));
        l_Alarm_Range->setGeometry(QRect(20, 60, 161, 31));
        QFont font10;
        font10.setPointSize(18);
        l_Alarm_Range->setFont(font10);
        l_OP_Mode = new QLabel(t_Control_OP);
        l_OP_Mode->setObjectName(QStringLiteral("l_OP_Mode"));
        l_OP_Mode->setGeometry(QRect(20, 115, 211, 21));
        l_OP_Mode->setFont(font10);
        l_GOP_Mode = new QLabel(t_Control_OP);
        l_GOP_Mode->setObjectName(QStringLiteral("l_GOP_Mode"));
        l_GOP_Mode->setGeometry(QRect(20, 155, 291, 26));
        l_GOP_Mode->setFont(font9);
        tb_ControlRange = new EditLine(t_Control_OP);
        tb_ControlRange->setObjectName(QStringLiteral("tb_ControlRange"));
        tb_ControlRange->setGeometry(QRect(340, 20, 116, 31));
        tb_ControlRange->setFont(font8);
        tb_AlarmRange = new EditLine(t_Control_OP);
        tb_AlarmRange->setObjectName(QStringLiteral("tb_AlarmRange"));
        tb_AlarmRange->setGeometry(QRect(340, 60, 116, 31));
        tb_AlarmRange->setFont(font8);
        cb_OpMode = new QComboBox(t_Control_OP);
        cb_OpMode->setObjectName(QStringLiteral("cb_OpMode"));
        cb_OpMode->setGeometry(QRect(340, 115, 236, 26));
        cb_OpMode->setFont(font8);
        cb_GOpMode = new QComboBox(t_Control_OP);
        cb_GOpMode->setObjectName(QStringLiteral("cb_GOpMode"));
        cb_GOpMode->setGeometry(QRect(340, 155, 236, 26));
        cb_GOpMode->setFont(font8);
        cb_O_Mode->addTab(t_Control_OP, QString());
        t_Graph = new QWidget();
        t_Graph->setObjectName(QStringLiteral("t_Graph"));
        cb_O_Mode->addTab(t_Graph, QString());
        b_Apply_Changes = new QPushButton(centralWidget);
        b_Apply_Changes->setObjectName(QStringLiteral("b_Apply_Changes"));
        b_Apply_Changes->setGeometry(QRect(610, 10, 181, 36));
        b_Apply_Changes->setFont(font10);
        cb_Module_Select = new QComboBox(centralWidget);
        cb_Module_Select->setObjectName(QStringLiteral("cb_Module_Select"));
        cb_Module_Select->setGeometry(QRect(385, 375, 406, 36));
        cb_Module_Select->setFont(font10);
        l_UserMessage = new QLabel(centralWidget);
        l_UserMessage->setObjectName(QStringLiteral("l_UserMessage"));
        l_UserMessage->setGeometry(QRect(15, 375, 346, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        l_UserMessage->setPalette(palette);
        QFont font11;
        font11.setPointSize(15);
        l_UserMessage->setFont(font11);
        l_UserMessage->setScaledContents(false);
        l_UserMessage->setWordWrap(true);
        m_monitron_0_0->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(m_monitron_0_0);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 36));
        m_monitron_0_0->setMenuBar(menuBar);
        sbar_Device_Informations = new QStatusBar(m_monitron_0_0);
        sbar_Device_Informations->setObjectName(QStringLiteral("sbar_Device_Informations"));
        QFont font12;
        font12.setPointSize(14);
        sbar_Device_Informations->setFont(font12);
        m_monitron_0_0->setStatusBar(sbar_Device_Informations);

        retranslateUi(m_monitron_0_0);

        cb_O_Mode->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(m_monitron_0_0);
    } // setupUi

    void retranslateUi(QMainWindow *m_monitron_0_0)
    {
        m_monitron_0_0->setWindowTitle(QApplication::translate("m_monitron_0_0", "Mini Monitron V0.0", 0));
#ifndef QT_NO_STATUSTIP
        m_monitron_0_0->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        l_Lecture->setText(QApplication::translate("m_monitron_0_0", "Reading:", 0));
        l_Setpoint->setText(QApplication::translate("m_monitron_0_0", "Setpoint:", 0));
        l_Taux_Var->setText(QApplication::translate("m_monitron_0_0", "Variation rate:", 0));
        l_current_Reading->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Lecture), QApplication::translate("m_monitron_0_0", "Reading", 0));
        l_Cycle_Mode_State->setText(QApplication::translate("m_monitron_0_0", "Cycle mode status:", 0));
        l_Setpoint_Cycle_1->setText(QApplication::translate("m_monitron_0_0", "Setpoint 1:", 0));
        l_Cycle2->setText(QApplication::translate("m_monitron_0_0", "Cycle 2:", 0));
        l_Setpoint_Cycle_2->setText(QApplication::translate("m_monitron_0_0", "Setpoint 2:", 0));
        l_Cycle1->setText(QApplication::translate("m_monitron_0_0", "Cycle 1:", 0));
        l_Cycle_Mode_Current_State->setText(QApplication::translate("m_monitron_0_0", "OFF", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Cycles), QApplication::translate("m_monitron_0_0", "Cycles", 0));
        l_Lecture_mV->setText(QApplication::translate("m_monitron_0_0", "Reading (mV):", 0));
        b_Calibration->setText(QApplication::translate("m_monitron_0_0", "Calibrate", 0));
        l_Val_Convertie->setText(QApplication::translate("m_monitron_0_0", "Converted value: ", 0));
        l_Lecture_mV_Current->setText(QString());
        l_Lecture_Converted_Current->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        l_P1_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Converted value P1:", 0));
        l_P2_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Converted value P2:", 0));
        l_RawValueP1->setText(QApplication::translate("m_monitron_0_0", "Raw Value P1:", 0));
        l_RawValueP2->setText(QApplication::translate("m_monitron_0_0", "Raw Value P2:", 0));
        l_RawValueP1_Current->setText(QString());
        l_RawValueP2_Current->setText(QString());
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Calibration), QApplication::translate("m_monitron_0_0", "Calibration", 0));
        l_Control_Range->setText(QApplication::translate("m_monitron_0_0", "Control range:", 0));
        l_Alarm_Range->setText(QApplication::translate("m_monitron_0_0", "Alarm range:", 0));
        l_OP_Mode->setText(QApplication::translate("m_monitron_0_0", "Operation Mode:", 0));
        l_GOP_Mode->setText(QApplication::translate("m_monitron_0_0", "Global Operation Mode:", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Control_OP), QApplication::translate("m_monitron_0_0", "Control & OP", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Graph), QApplication::translate("m_monitron_0_0", "Graph", 0));
        b_Apply_Changes->setText(QApplication::translate("m_monitron_0_0", "Apply changes", 0));
        l_UserMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class m_monitron_0_0: public Ui_m_monitron_0_0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_MONITRON_0_0_H
