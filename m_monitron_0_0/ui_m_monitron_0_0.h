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
#include <QtWidgets/QGroupBox>
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
    QGroupBox *gb_Point1;
    QLabel *l_P1_mV;
    QLabel *l_P1_Convert_Unit;
    QLabel *l_Current_P1_raw;
    QLabel *l_Current_P1_converted;
    QPushButton *b_Edit_tCalibration;
    QLabel *l_Val_Convertie;
    QGroupBox *gb_Point2;
    QLabel *l_P2_mV;
    QLabel *l_P2_Convert_Unit;
    QLabel *l_Current_P2_raw;
    QLabel *l_Current_P2_converted;
    QLabel *l_Lecture_mV_Current;
    QLabel *l_Lecture_Converted_Current;
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
        centralWidget = new QWidget(m_monitron_0_0);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cb_O_Mode = new QTabWidget(centralWidget);
        cb_O_Mode->setObjectName(QStringLiteral("cb_O_Mode"));
        cb_O_Mode->setGeometry(QRect(10, 15, 781, 351));
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
        l_current_Reading->setGeometry(QRect(315, 40, 131, 36));
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
        gb_Point1 = new QGroupBox(t_Calibration);
        gb_Point1->setObjectName(QStringLiteral("gb_Point1"));
        gb_Point1->setGeometry(QRect(20, 145, 301, 161));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        gb_Point1->setFont(font5);
        l_P1_mV = new QLabel(gb_Point1);
        l_P1_mV->setObjectName(QStringLiteral("l_P1_mV"));
        l_P1_mV->setGeometry(QRect(10, 50, 171, 21));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setWeight(50);
        l_P1_mV->setFont(font6);
        l_P1_Convert_Unit = new QLabel(gb_Point1);
        l_P1_Convert_Unit->setObjectName(QStringLiteral("l_P1_Convert_Unit"));
        l_P1_Convert_Unit->setGeometry(QRect(10, 90, 186, 16));
        l_P1_Convert_Unit->setFont(font6);
        l_Current_P1_raw = new QLabel(gb_Point1);
        l_Current_P1_raw->setObjectName(QStringLiteral("l_Current_P1_raw"));
        l_Current_P1_raw->setGeometry(QRect(200, 50, 67, 21));
        l_Current_P1_converted = new QLabel(gb_Point1);
        l_Current_P1_converted->setObjectName(QStringLiteral("l_Current_P1_converted"));
        l_Current_P1_converted->setGeometry(QRect(200, 90, 67, 21));
        b_Edit_tCalibration = new QPushButton(t_Calibration);
        b_Edit_tCalibration->setObjectName(QStringLiteral("b_Edit_tCalibration"));
        b_Edit_tCalibration->setGeometry(QRect(655, 10, 116, 66));
        l_Val_Convertie = new QLabel(t_Calibration);
        l_Val_Convertie->setObjectName(QStringLiteral("l_Val_Convertie"));
        l_Val_Convertie->setGeometry(QRect(20, 75, 281, 31));
        QFont font7;
        font7.setPointSize(24);
        font7.setItalic(false);
        l_Val_Convertie->setFont(font7);
        gb_Point2 = new QGroupBox(t_Calibration);
        gb_Point2->setObjectName(QStringLiteral("gb_Point2"));
        gb_Point2->setGeometry(QRect(380, 145, 301, 161));
        gb_Point2->setFont(font5);
        l_P2_mV = new QLabel(gb_Point2);
        l_P2_mV->setObjectName(QStringLiteral("l_P2_mV"));
        l_P2_mV->setGeometry(QRect(10, 50, 176, 21));
        l_P2_mV->setFont(font6);
        l_P2_Convert_Unit = new QLabel(gb_Point2);
        l_P2_Convert_Unit->setObjectName(QStringLiteral("l_P2_Convert_Unit"));
        l_P2_Convert_Unit->setGeometry(QRect(10, 90, 186, 16));
        l_P2_Convert_Unit->setFont(font6);
        l_Current_P2_raw = new QLabel(gb_Point2);
        l_Current_P2_raw->setObjectName(QStringLiteral("l_Current_P2_raw"));
        l_Current_P2_raw->setGeometry(QRect(200, 50, 67, 21));
        l_Current_P2_converted = new QLabel(gb_Point2);
        l_Current_P2_converted->setObjectName(QStringLiteral("l_Current_P2_converted"));
        l_Current_P2_converted->setGeometry(QRect(200, 86, 67, 21));
        l_Lecture_mV_Current = new QLabel(t_Calibration);
        l_Lecture_mV_Current->setObjectName(QStringLiteral("l_Lecture_mV_Current"));
        l_Lecture_mV_Current->setGeometry(QRect(310, 30, 136, 26));
        QFont font8;
        font8.setPointSize(22);
        font8.setBold(true);
        font8.setWeight(75);
        l_Lecture_mV_Current->setFont(font8);
        l_Lecture_Converted_Current = new QLabel(t_Calibration);
        l_Lecture_Converted_Current->setObjectName(QStringLiteral("l_Lecture_Converted_Current"));
        l_Lecture_Converted_Current->setGeometry(QRect(310, 80, 156, 26));
        l_Lecture_Converted_Current->setFont(font8);
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
        QFont font11;
        font11.setPointSize(20);
        font11.setBold(true);
        font11.setWeight(75);
        tb_ControlRange->setFont(font11);
        tb_AlarmRange = new EditLine(t_Control_OP);
        tb_AlarmRange->setObjectName(QStringLiteral("tb_AlarmRange"));
        tb_AlarmRange->setGeometry(QRect(340, 60, 116, 31));
        tb_AlarmRange->setFont(font11);
        cb_OpMode = new QComboBox(t_Control_OP);
        cb_OpMode->setObjectName(QStringLiteral("cb_OpMode"));
        cb_OpMode->setGeometry(QRect(340, 115, 116, 26));
        cb_OpMode->setFont(font11);
        cb_GOpMode = new QComboBox(t_Control_OP);
        cb_GOpMode->setObjectName(QStringLiteral("cb_GOpMode"));
        cb_GOpMode->setGeometry(QRect(340, 155, 116, 26));
        cb_GOpMode->setFont(font11);
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
        cb_Module_Select->setGeometry(QRect(430, 375, 361, 36));
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

        cb_O_Mode->setCurrentIndex(0);


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
        gb_Point1->setTitle(QApplication::translate("m_monitron_0_0", "Calibration point #1", 0));
        l_P1_mV->setText(QApplication::translate("m_monitron_0_0", "Raw value (mV):", 0));
        l_P1_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Converted value:", 0));
        l_Current_P1_raw->setText(QString());
        l_Current_P1_converted->setText(QString());
        b_Edit_tCalibration->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        l_Val_Convertie->setText(QApplication::translate("m_monitron_0_0", "Converted value: ", 0));
        gb_Point2->setTitle(QApplication::translate("m_monitron_0_0", "Calibration point #2", 0));
        l_P2_mV->setText(QApplication::translate("m_monitron_0_0", "Raw value (mV):", 0));
        l_P2_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Converted value:", 0));
        l_Current_P2_raw->setText(QString());
        l_Current_P2_converted->setText(QString());
        l_Lecture_mV_Current->setText(QString());
        l_Lecture_Converted_Current->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Calibration), QApplication::translate("m_monitron_0_0", "Calibration", 0));
        l_Control_Range->setText(QApplication::translate("m_monitron_0_0", "Control range:", 0));
        l_Alarm_Range->setText(QApplication::translate("m_monitron_0_0", "Alarm range:", 0));
        l_OP_Mode->setText(QApplication::translate("m_monitron_0_0", "Operation Mode:", 0));
        l_GOP_Mode->setText(QApplication::translate("m_monitron_0_0", "Global Operation Mode:", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Control_OP), QApplication::translate("m_monitron_0_0", "Control & OP", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Graph), QApplication::translate("m_monitron_0_0", "Graph", 0));
        b_Apply_Changes->setText(QApplication::translate("m_monitron_0_0", "Apply changes", 0));
    } // retranslateUi

};

namespace Ui {
    class m_monitron_0_0: public Ui_m_monitron_0_0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_MONITRON_0_0_H
