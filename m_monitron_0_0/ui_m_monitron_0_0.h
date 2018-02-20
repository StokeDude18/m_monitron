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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

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
    QPushButton *b_Edit_tLecture;
    QLabel *l_Current_Setpoint;
    QLabel *l_Current_Var_Rate;
    QLabel *l_current_Reading;
    QWidget *t_Cycles;
    QLabel *l_Cycle_Mode_State;
    QPushButton *b_Edit_tCycles;
    QLabel *l_Setpoint_Cycle_1;
    QLabel *l_Cycle2;
    QLabel *l_Setpoint_Cycle_2;
    QLabel *l_Cycle1;
    QLabel *l_Current_Cycle_1;
    QLabel *l_Current_Cycle_2;
    QLabel *l_Current_Cycle_Setpoint_1;
    QLabel *l_Current_Cycle_Setpoint_2;
    QLabel *l_Cycle_Mode_Current_State;
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
    QWidget *t_Control_OP;
    QLabel *l_COntrol_Range;
    QLabel *l_Alarm_Range;
    QLabel *l_Down_Limit;
    QLabel *l_Upper_limit;
    QLabel *l_OP_Mode;
    QLabel *l_GOP_Mode;
    QPushButton *b_Edit_tControl;
    QLabel *l_Current_Control_Range;
    QLabel *l_Current_Range_Low;
    QLabel *l_Current_Range_Up;
    QLabel *l_Current_Operation_Mode;
    QLabel *l_Current_Gloabal_Operation_Mode;
    QWidget *t_Graph;
    QPushButton *b_Apply_Changes;
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
        cb_O_Mode->setGeometry(QRect(10, 15, 781, 401));
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
        b_Edit_tLecture = new QPushButton(t_Lecture);
        b_Edit_tLecture->setObjectName(QStringLiteral("b_Edit_tLecture"));
        b_Edit_tLecture->setGeometry(QRect(655, 10, 116, 66));
        l_Current_Setpoint = new QLabel(t_Lecture);
        l_Current_Setpoint->setObjectName(QStringLiteral("l_Current_Setpoint"));
        l_Current_Setpoint->setGeometry(QRect(315, 110, 136, 36));
        QFont font3;
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        l_Current_Setpoint->setFont(font3);
        l_Current_Var_Rate = new QLabel(t_Lecture);
        l_Current_Var_Rate->setObjectName(QStringLiteral("l_Current_Var_Rate"));
        l_Current_Var_Rate->setGeometry(QRect(315, 185, 141, 31));
        l_Current_Var_Rate->setFont(font3);
        l_current_Reading = new QLabel(t_Lecture);
        l_current_Reading->setObjectName(QStringLiteral("l_current_Reading"));
        l_current_Reading->setGeometry(QRect(315, 40, 131, 36));
        l_current_Reading->setFont(font3);
        cb_O_Mode->addTab(t_Lecture, QString());
        t_Cycles = new QWidget();
        t_Cycles->setObjectName(QStringLiteral("t_Cycles"));
        l_Cycle_Mode_State = new QLabel(t_Cycles);
        l_Cycle_Mode_State->setObjectName(QStringLiteral("l_Cycle_Mode_State"));
        l_Cycle_Mode_State->setGeometry(QRect(20, 25, 391, 46));
        l_Cycle_Mode_State->setFont(font2);
        b_Edit_tCycles = new QPushButton(t_Cycles);
        b_Edit_tCycles->setObjectName(QStringLiteral("b_Edit_tCycles"));
        b_Edit_tCycles->setGeometry(QRect(655, 10, 116, 66));
        l_Setpoint_Cycle_1 = new QLabel(t_Cycles);
        l_Setpoint_Cycle_1->setObjectName(QStringLiteral("l_Setpoint_Cycle_1"));
        l_Setpoint_Cycle_1->setGeometry(QRect(250, 110, 166, 36));
        QFont font4;
        font4.setPointSize(24);
        l_Setpoint_Cycle_1->setFont(font4);
        l_Cycle2 = new QLabel(t_Cycles);
        l_Cycle2->setObjectName(QStringLiteral("l_Cycle2"));
        l_Cycle2->setGeometry(QRect(20, 190, 116, 36));
        l_Cycle2->setFont(font4);
        l_Setpoint_Cycle_2 = new QLabel(t_Cycles);
        l_Setpoint_Cycle_2->setObjectName(QStringLiteral("l_Setpoint_Cycle_2"));
        l_Setpoint_Cycle_2->setGeometry(QRect(250, 190, 166, 36));
        l_Setpoint_Cycle_2->setFont(font4);
        l_Cycle1 = new QLabel(t_Cycles);
        l_Cycle1->setObjectName(QStringLiteral("l_Cycle1"));
        l_Cycle1->setGeometry(QRect(20, 110, 116, 36));
        l_Cycle1->setFont(font4);
        l_Current_Cycle_1 = new QLabel(t_Cycles);
        l_Current_Cycle_1->setObjectName(QStringLiteral("l_Current_Cycle_1"));
        l_Current_Cycle_1->setGeometry(QRect(140, 115, 66, 26));
        QFont font5;
        font5.setPointSize(24);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        l_Current_Cycle_1->setFont(font5);
        l_Current_Cycle_2 = new QLabel(t_Cycles);
        l_Current_Cycle_2->setObjectName(QStringLiteral("l_Current_Cycle_2"));
        l_Current_Cycle_2->setGeometry(QRect(140, 195, 71, 26));
        l_Current_Cycle_2->setFont(font5);
        l_Current_Cycle_Setpoint_1 = new QLabel(t_Cycles);
        l_Current_Cycle_Setpoint_1->setObjectName(QStringLiteral("l_Current_Cycle_Setpoint_1"));
        l_Current_Cycle_Setpoint_1->setGeometry(QRect(420, 115, 71, 26));
        l_Current_Cycle_Setpoint_1->setFont(font5);
        l_Current_Cycle_Setpoint_2 = new QLabel(t_Cycles);
        l_Current_Cycle_Setpoint_2->setObjectName(QStringLiteral("l_Current_Cycle_Setpoint_2"));
        l_Current_Cycle_Setpoint_2->setGeometry(QRect(420, 195, 66, 26));
        l_Current_Cycle_Setpoint_2->setFont(font5);
        l_Cycle_Mode_Current_State = new QLabel(t_Cycles);
        l_Cycle_Mode_Current_State->setObjectName(QStringLiteral("l_Cycle_Mode_Current_State"));
        l_Cycle_Mode_Current_State->setGeometry(QRect(420, 30, 86, 41));
        l_Cycle_Mode_Current_State->setFont(font3);
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
        QFont font6;
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setWeight(75);
        gb_Point1->setFont(font6);
        l_P1_mV = new QLabel(gb_Point1);
        l_P1_mV->setObjectName(QStringLiteral("l_P1_mV"));
        l_P1_mV->setGeometry(QRect(10, 50, 156, 21));
        QFont font7;
        font7.setPointSize(16);
        font7.setBold(false);
        font7.setWeight(50);
        l_P1_mV->setFont(font7);
        l_P1_Convert_Unit = new QLabel(gb_Point1);
        l_P1_Convert_Unit->setObjectName(QStringLiteral("l_P1_Convert_Unit"));
        l_P1_Convert_Unit->setGeometry(QRect(10, 90, 166, 16));
        l_P1_Convert_Unit->setFont(font7);
        l_Current_P1_raw = new QLabel(gb_Point1);
        l_Current_P1_raw->setObjectName(QStringLiteral("l_Current_P1_raw"));
        l_Current_P1_raw->setGeometry(QRect(180, 55, 67, 17));
        l_Current_P1_converted = new QLabel(gb_Point1);
        l_Current_P1_converted->setObjectName(QStringLiteral("l_Current_P1_converted"));
        l_Current_P1_converted->setGeometry(QRect(180, 90, 67, 17));
        b_Edit_tCalibration = new QPushButton(t_Calibration);
        b_Edit_tCalibration->setObjectName(QStringLiteral("b_Edit_tCalibration"));
        b_Edit_tCalibration->setGeometry(QRect(655, 10, 116, 66));
        l_Val_Convertie = new QLabel(t_Calibration);
        l_Val_Convertie->setObjectName(QStringLiteral("l_Val_Convertie"));
        l_Val_Convertie->setGeometry(QRect(20, 75, 281, 31));
        QFont font8;
        font8.setPointSize(24);
        font8.setItalic(false);
        l_Val_Convertie->setFont(font8);
        gb_Point2 = new QGroupBox(t_Calibration);
        gb_Point2->setObjectName(QStringLiteral("gb_Point2"));
        gb_Point2->setGeometry(QRect(380, 145, 301, 161));
        gb_Point2->setFont(font6);
        l_P2_mV = new QLabel(gb_Point2);
        l_P2_mV->setObjectName(QStringLiteral("l_P2_mV"));
        l_P2_mV->setGeometry(QRect(10, 50, 156, 21));
        l_P2_mV->setFont(font7);
        l_P2_Convert_Unit = new QLabel(gb_Point2);
        l_P2_Convert_Unit->setObjectName(QStringLiteral("l_P2_Convert_Unit"));
        l_P2_Convert_Unit->setGeometry(QRect(10, 90, 166, 16));
        l_P2_Convert_Unit->setFont(font7);
        l_Current_P2_raw = new QLabel(gb_Point2);
        l_Current_P2_raw->setObjectName(QStringLiteral("l_Current_P2_raw"));
        l_Current_P2_raw->setGeometry(QRect(180, 55, 67, 17));
        l_Current_P2_converted = new QLabel(gb_Point2);
        l_Current_P2_converted->setObjectName(QStringLiteral("l_Current_P2_converted"));
        l_Current_P2_converted->setGeometry(QRect(180, 90, 67, 17));
        cb_O_Mode->addTab(t_Calibration, QString());
        t_Control_OP = new QWidget();
        t_Control_OP->setObjectName(QStringLiteral("t_Control_OP"));
        l_COntrol_Range = new QLabel(t_Control_OP);
        l_COntrol_Range->setObjectName(QStringLiteral("l_COntrol_Range"));
        l_COntrol_Range->setGeometry(QRect(20, 20, 176, 31));
        QFont font9;
        font9.setPointSize(18);
        font9.setItalic(false);
        l_COntrol_Range->setFont(font9);
        l_Alarm_Range = new QLabel(t_Control_OP);
        l_Alarm_Range->setObjectName(QStringLiteral("l_Alarm_Range"));
        l_Alarm_Range->setGeometry(QRect(20, 60, 271, 31));
        QFont font10;
        font10.setPointSize(18);
        l_Alarm_Range->setFont(font10);
        l_Down_Limit = new QLabel(t_Control_OP);
        l_Down_Limit->setObjectName(QStringLiteral("l_Down_Limit"));
        l_Down_Limit->setGeometry(QRect(35, 105, 56, 21));
        QFont font11;
        font11.setPointSize(15);
        l_Down_Limit->setFont(font11);
        l_Upper_limit = new QLabel(t_Control_OP);
        l_Upper_limit->setObjectName(QStringLiteral("l_Upper_limit"));
        l_Upper_limit->setGeometry(QRect(190, 105, 31, 21));
        l_Upper_limit->setFont(font11);
        l_OP_Mode = new QLabel(t_Control_OP);
        l_OP_Mode->setObjectName(QStringLiteral("l_OP_Mode"));
        l_OP_Mode->setGeometry(QRect(20, 150, 211, 21));
        l_OP_Mode->setFont(font10);
        l_GOP_Mode = new QLabel(t_Control_OP);
        l_GOP_Mode->setObjectName(QStringLiteral("l_GOP_Mode"));
        l_GOP_Mode->setGeometry(QRect(20, 190, 291, 26));
        l_GOP_Mode->setFont(font9);
        b_Edit_tControl = new QPushButton(t_Control_OP);
        b_Edit_tControl->setObjectName(QStringLiteral("b_Edit_tControl"));
        b_Edit_tControl->setGeometry(QRect(655, 10, 116, 66));
        l_Current_Control_Range = new QLabel(t_Control_OP);
        l_Current_Control_Range->setObjectName(QStringLiteral("l_Current_Control_Range"));
        l_Current_Control_Range->setGeometry(QRect(320, 25, 66, 21));
        QFont font12;
        font12.setPointSize(20);
        font12.setBold(true);
        font12.setWeight(75);
        l_Current_Control_Range->setFont(font12);
        l_Current_Range_Low = new QLabel(t_Control_OP);
        l_Current_Range_Low->setObjectName(QStringLiteral("l_Current_Range_Low"));
        l_Current_Range_Low->setGeometry(QRect(100, 105, 36, 21));
        QFont font13;
        font13.setPointSize(16);
        font13.setBold(true);
        font13.setWeight(75);
        l_Current_Range_Low->setFont(font13);
        l_Current_Range_Up = new QLabel(t_Control_OP);
        l_Current_Range_Up->setObjectName(QStringLiteral("l_Current_Range_Up"));
        l_Current_Range_Up->setGeometry(QRect(230, 105, 36, 21));
        l_Current_Range_Up->setFont(font13);
        l_Current_Operation_Mode = new QLabel(t_Control_OP);
        l_Current_Operation_Mode->setObjectName(QStringLiteral("l_Current_Operation_Mode"));
        l_Current_Operation_Mode->setGeometry(QRect(320, 150, 66, 21));
        l_Current_Operation_Mode->setFont(font12);
        l_Current_Gloabal_Operation_Mode = new QLabel(t_Control_OP);
        l_Current_Gloabal_Operation_Mode->setObjectName(QStringLiteral("l_Current_Gloabal_Operation_Mode"));
        l_Current_Gloabal_Operation_Mode->setGeometry(QRect(320, 195, 66, 21));
        l_Current_Gloabal_Operation_Mode->setFont(font12);
        cb_O_Mode->addTab(t_Control_OP, QString());
        t_Graph = new QWidget();
        t_Graph->setObjectName(QStringLiteral("t_Graph"));
        cb_O_Mode->addTab(t_Graph, QString());
        b_Apply_Changes = new QPushButton(centralWidget);
        b_Apply_Changes->setObjectName(QStringLiteral("b_Apply_Changes"));
        b_Apply_Changes->setGeometry(QRect(610, 10, 181, 41));
        b_Apply_Changes->setFont(font10);
        m_monitron_0_0->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(m_monitron_0_0);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 38));
        m_monitron_0_0->setMenuBar(menuBar);
        sbar_Device_Informations = new QStatusBar(m_monitron_0_0);
        sbar_Device_Informations->setObjectName(QStringLiteral("sbar_Device_Informations"));
        sbar_Device_Informations->setFont(font1);
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
        b_Edit_tLecture->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        l_Current_Setpoint->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        l_Current_Var_Rate->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        l_current_Reading->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Lecture), QApplication::translate("m_monitron_0_0", "Reading", 0));
        l_Cycle_Mode_State->setText(QApplication::translate("m_monitron_0_0", "Cycle mode status:", 0));
        b_Edit_tCycles->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        l_Setpoint_Cycle_1->setText(QApplication::translate("m_monitron_0_0", "Setpoint 1:", 0));
        l_Cycle2->setText(QApplication::translate("m_monitron_0_0", "Cycle 2:", 0));
        l_Setpoint_Cycle_2->setText(QApplication::translate("m_monitron_0_0", "Setpoint 2:", 0));
        l_Cycle1->setText(QApplication::translate("m_monitron_0_0", "Cycle 1:", 0));
        l_Current_Cycle_1->setText(QApplication::translate("m_monitron_0_0", "1", 0));
        l_Current_Cycle_2->setText(QApplication::translate("m_monitron_0_0", "2", 0));
        l_Current_Cycle_Setpoint_1->setText(QApplication::translate("m_monitron_0_0", "1", 0));
        l_Current_Cycle_Setpoint_2->setText(QApplication::translate("m_monitron_0_0", "2", 0));
        l_Cycle_Mode_Current_State->setText(QApplication::translate("m_monitron_0_0", "OFF", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Cycles), QApplication::translate("m_monitron_0_0", "Cycles", 0));
        l_Lecture_mV->setText(QApplication::translate("m_monitron_0_0", "Reading (mV):", 0));
        gb_Point1->setTitle(QApplication::translate("m_monitron_0_0", "Calibration point #1", 0));
        l_P1_mV->setText(QApplication::translate("m_monitron_0_0", "Raw value (mV):", 0));
        l_P1_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Converted value:", 0));
        l_Current_P1_raw->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        l_Current_P1_converted->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        b_Edit_tCalibration->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        l_Val_Convertie->setText(QApplication::translate("m_monitron_0_0", "Converted value: ", 0));
        gb_Point2->setTitle(QApplication::translate("m_monitron_0_0", "Calibration point #1", 0));
        l_P2_mV->setText(QApplication::translate("m_monitron_0_0", "Raw value (mV):", 0));
        l_P2_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Converted value:", 0));
        l_Current_P2_raw->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        l_Current_P2_converted->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Calibration), QApplication::translate("m_monitron_0_0", "Calibration", 0));
        l_COntrol_Range->setText(QApplication::translate("m_monitron_0_0", "Control range:", 0));
        l_Alarm_Range->setText(QApplication::translate("m_monitron_0_0", "Safe operation range:", 0));
        l_Down_Limit->setText(QApplication::translate("m_monitron_0_0", "From:", 0));
        l_Upper_limit->setText(QApplication::translate("m_monitron_0_0", "To:", 0));
        l_OP_Mode->setText(QApplication::translate("m_monitron_0_0", "Operation Mode:", 0));
        l_GOP_Mode->setText(QApplication::translate("m_monitron_0_0", "Global Operation Mode:", 0));
        b_Edit_tControl->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        l_Current_Control_Range->setText(QApplication::translate("m_monitron_0_0", "X", 0));
        l_Current_Range_Low->setText(QApplication::translate("m_monitron_0_0", "X", 0));
        l_Current_Range_Up->setText(QApplication::translate("m_monitron_0_0", "X", 0));
        l_Current_Operation_Mode->setText(QApplication::translate("m_monitron_0_0", "X", 0));
        l_Current_Gloabal_Operation_Mode->setText(QApplication::translate("m_monitron_0_0", "X", 0));
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
