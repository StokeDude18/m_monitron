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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
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
    QWidget *t_Cycles;
    QLabel *l_StartCycles;
    QLineEdit *tb_Start_Cycle;
    QLabel *l_Cycle1;
    QLineEdit *tb_Cycle1;
    QLineEdit *tb_Cycle2;
    QLabel *l_Cycle2;
    QLineEdit *tb_Cycle2_2;
    QLineEdit *tb_Cycle1_2;
    QLabel *l_Setpoint_Cycle_2;
    QLabel *l_Setpoint_Cycle_1;
    QPushButton *b_Edit_tCycles;
    QWidget *t_Calibration;
    QLabel *l_Lecture_mV;
    QGroupBox *gb_Point1;
    QLabel *l_P1_mV;
    QLineEdit *tb_P1_mV;
    QLabel *l_P1_Convert_Unit;
    QLineEdit *tb_P1Convert_Unit;
    QGroupBox *gb_Point2;
    QLabel *l_P2_mV;
    QLineEdit *tb_P2_mV;
    QLabel *l_P2_Convert_Unit;
    QLineEdit *tb_P2_Convert_Unit;
    QPushButton *b_Edit_tCalibration;
    QWidget *t_Control_OP;
    QLabel *l_COntrol_Range;
    QLineEdit *tb_Control_Range;
    QLabel *l_Alarm_Range;
    QLineEdit *tb_Lowe_Limit;
    QLabel *l_Down_Limit;
    QLabel *l_Upper_limit;
    QLineEdit *tb_Upper_Limit;
    QLabel *l_OP_Mode;
    QComboBox *comboBox;
    QLabel *l_GOP_Mode;
    QComboBox *cb_GOP_Mode;
    QPushButton *b_Apply_Changes_GOP;
    QPushButton *b_Edit_tControl;
    QWidget *t_Graph;
    QLabel *l_ID_Module;
    QLabel *l_Position_Module;
    QPushButton *b_Apply_Changes;
    QLabel *l_Sensor_Type;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *m_monitron_0_0)
    {
        if (m_monitron_0_0->objectName().isEmpty())
            m_monitron_0_0->setObjectName(QStringLiteral("m_monitron_0_0"));
        m_monitron_0_0->resize(740, 506);
        centralWidget = new QWidget(m_monitron_0_0);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cb_O_Mode = new QTabWidget(centralWidget);
        cb_O_Mode->setObjectName(QStringLiteral("cb_O_Mode"));
        cb_O_Mode->setGeometry(QRect(30, 80, 681, 361));
        t_Lecture = new QWidget();
        t_Lecture->setObjectName(QStringLiteral("t_Lecture"));
        l_Lecture = new QLabel(t_Lecture);
        l_Lecture->setObjectName(QStringLiteral("l_Lecture"));
        l_Lecture->setGeometry(QRect(20, 30, 301, 20));
        QFont font;
        font.setPointSize(12);
        l_Lecture->setFont(font);
        l_Setpoint = new QLabel(t_Lecture);
        l_Setpoint->setObjectName(QStringLiteral("l_Setpoint"));
        l_Setpoint->setGeometry(QRect(20, 70, 81, 20));
        l_Setpoint->setFont(font);
        l_Taux_Var = new QLabel(t_Lecture);
        l_Taux_Var->setObjectName(QStringLiteral("l_Taux_Var"));
        l_Taux_Var->setGeometry(QRect(20, 110, 151, 16));
        l_Taux_Var->setFont(font);
        b_Edit_tLecture = new QPushButton(t_Lecture);
        b_Edit_tLecture->setObjectName(QStringLiteral("b_Edit_tLecture"));
        b_Edit_tLecture->setGeometry(QRect(570, 20, 81, 41));
        l_Current_Setpoint = new QLabel(t_Lecture);
        l_Current_Setpoint->setObjectName(QStringLiteral("l_Current_Setpoint"));
        l_Current_Setpoint->setGeometry(QRect(180, 70, 59, 14));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        l_Current_Setpoint->setFont(font1);
        l_Current_Var_Rate = new QLabel(t_Lecture);
        l_Current_Var_Rate->setObjectName(QStringLiteral("l_Current_Var_Rate"));
        l_Current_Var_Rate->setGeometry(QRect(180, 110, 59, 14));
        l_Current_Var_Rate->setFont(font1);
        cb_O_Mode->addTab(t_Lecture, QString());
        t_Cycles = new QWidget();
        t_Cycles->setObjectName(QStringLiteral("t_Cycles"));
        l_StartCycles = new QLabel(t_Cycles);
        l_StartCycles->setObjectName(QStringLiteral("l_StartCycles"));
        l_StartCycles->setGeometry(QRect(20, 30, 101, 16));
        l_StartCycles->setFont(font);
        tb_Start_Cycle = new QLineEdit(t_Cycles);
        tb_Start_Cycle->setObjectName(QStringLiteral("tb_Start_Cycle"));
        tb_Start_Cycle->setGeometry(QRect(130, 30, 141, 22));
        l_Cycle1 = new QLabel(t_Cycles);
        l_Cycle1->setObjectName(QStringLiteral("l_Cycle1"));
        l_Cycle1->setGeometry(QRect(20, 70, 71, 16));
        l_Cycle1->setFont(font);
        tb_Cycle1 = new QLineEdit(t_Cycles);
        tb_Cycle1->setObjectName(QStringLiteral("tb_Cycle1"));
        tb_Cycle1->setGeometry(QRect(130, 70, 141, 22));
        tb_Cycle2 = new QLineEdit(t_Cycles);
        tb_Cycle2->setObjectName(QStringLiteral("tb_Cycle2"));
        tb_Cycle2->setGeometry(QRect(130, 110, 141, 22));
        l_Cycle2 = new QLabel(t_Cycles);
        l_Cycle2->setObjectName(QStringLiteral("l_Cycle2"));
        l_Cycle2->setGeometry(QRect(20, 110, 71, 16));
        l_Cycle2->setFont(font);
        tb_Cycle2_2 = new QLineEdit(t_Cycles);
        tb_Cycle2_2->setObjectName(QStringLiteral("tb_Cycle2_2"));
        tb_Cycle2_2->setGeometry(QRect(420, 110, 141, 22));
        tb_Cycle1_2 = new QLineEdit(t_Cycles);
        tb_Cycle1_2->setObjectName(QStringLiteral("tb_Cycle1_2"));
        tb_Cycle1_2->setGeometry(QRect(420, 70, 141, 22));
        l_Setpoint_Cycle_2 = new QLabel(t_Cycles);
        l_Setpoint_Cycle_2->setObjectName(QStringLiteral("l_Setpoint_Cycle_2"));
        l_Setpoint_Cycle_2->setGeometry(QRect(310, 110, 91, 16));
        l_Setpoint_Cycle_2->setFont(font);
        l_Setpoint_Cycle_1 = new QLabel(t_Cycles);
        l_Setpoint_Cycle_1->setObjectName(QStringLiteral("l_Setpoint_Cycle_1"));
        l_Setpoint_Cycle_1->setGeometry(QRect(310, 70, 91, 16));
        l_Setpoint_Cycle_1->setFont(font);
        b_Edit_tCycles = new QPushButton(t_Cycles);
        b_Edit_tCycles->setObjectName(QStringLiteral("b_Edit_tCycles"));
        b_Edit_tCycles->setGeometry(QRect(570, 20, 81, 41));
        cb_O_Mode->addTab(t_Cycles, QString());
        t_Calibration = new QWidget();
        t_Calibration->setObjectName(QStringLiteral("t_Calibration"));
        l_Lecture_mV = new QLabel(t_Calibration);
        l_Lecture_mV->setObjectName(QStringLiteral("l_Lecture_mV"));
        l_Lecture_mV->setGeometry(QRect(20, 30, 191, 16));
        QFont font2;
        font2.setPointSize(14);
        l_Lecture_mV->setFont(font2);
        gb_Point1 = new QGroupBox(t_Calibration);
        gb_Point1->setObjectName(QStringLiteral("gb_Point1"));
        gb_Point1->setGeometry(QRect(20, 90, 301, 221));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        gb_Point1->setFont(font3);
        l_P1_mV = new QLabel(gb_Point1);
        l_P1_mV->setObjectName(QStringLiteral("l_P1_mV"));
        l_P1_mV->setGeometry(QRect(10, 50, 101, 16));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        l_P1_mV->setFont(font4);
        tb_P1_mV = new QLineEdit(gb_Point1);
        tb_P1_mV->setObjectName(QStringLiteral("tb_P1_mV"));
        tb_P1_mV->setGeometry(QRect(150, 50, 131, 21));
        l_P1_Convert_Unit = new QLabel(gb_Point1);
        l_P1_Convert_Unit->setObjectName(QStringLiteral("l_P1_Convert_Unit"));
        l_P1_Convert_Unit->setGeometry(QRect(10, 90, 131, 16));
        l_P1_Convert_Unit->setFont(font4);
        tb_P1Convert_Unit = new QLineEdit(gb_Point1);
        tb_P1Convert_Unit->setObjectName(QStringLiteral("tb_P1Convert_Unit"));
        tb_P1Convert_Unit->setGeometry(QRect(150, 90, 131, 21));
        gb_Point2 = new QGroupBox(t_Calibration);
        gb_Point2->setObjectName(QStringLiteral("gb_Point2"));
        gb_Point2->setGeometry(QRect(350, 90, 301, 221));
        gb_Point2->setFont(font3);
        l_P2_mV = new QLabel(gb_Point2);
        l_P2_mV->setObjectName(QStringLiteral("l_P2_mV"));
        l_P2_mV->setGeometry(QRect(10, 50, 101, 16));
        l_P2_mV->setFont(font4);
        tb_P2_mV = new QLineEdit(gb_Point2);
        tb_P2_mV->setObjectName(QStringLiteral("tb_P2_mV"));
        tb_P2_mV->setGeometry(QRect(150, 50, 131, 21));
        l_P2_Convert_Unit = new QLabel(gb_Point2);
        l_P2_Convert_Unit->setObjectName(QStringLiteral("l_P2_Convert_Unit"));
        l_P2_Convert_Unit->setGeometry(QRect(10, 90, 131, 16));
        l_P2_Convert_Unit->setFont(font4);
        tb_P2_Convert_Unit = new QLineEdit(gb_Point2);
        tb_P2_Convert_Unit->setObjectName(QStringLiteral("tb_P2_Convert_Unit"));
        tb_P2_Convert_Unit->setGeometry(QRect(150, 90, 131, 21));
        b_Edit_tCalibration = new QPushButton(t_Calibration);
        b_Edit_tCalibration->setObjectName(QStringLiteral("b_Edit_tCalibration"));
        b_Edit_tCalibration->setGeometry(QRect(570, 20, 81, 41));
        cb_O_Mode->addTab(t_Calibration, QString());
        t_Control_OP = new QWidget();
        t_Control_OP->setObjectName(QStringLiteral("t_Control_OP"));
        l_COntrol_Range = new QLabel(t_Control_OP);
        l_COntrol_Range->setObjectName(QStringLiteral("l_COntrol_Range"));
        l_COntrol_Range->setGeometry(QRect(20, 20, 121, 21));
        l_COntrol_Range->setFont(font);
        tb_Control_Range = new QLineEdit(t_Control_OP);
        tb_Control_Range->setObjectName(QStringLiteral("tb_Control_Range"));
        tb_Control_Range->setGeometry(QRect(160, 20, 113, 22));
        l_Alarm_Range = new QLabel(t_Control_OP);
        l_Alarm_Range->setObjectName(QStringLiteral("l_Alarm_Range"));
        l_Alarm_Range->setGeometry(QRect(20, 60, 181, 21));
        l_Alarm_Range->setFont(font);
        tb_Lowe_Limit = new QLineEdit(t_Control_OP);
        tb_Lowe_Limit->setObjectName(QStringLiteral("tb_Lowe_Limit"));
        tb_Lowe_Limit->setGeometry(QRect(80, 100, 41, 21));
        l_Down_Limit = new QLabel(t_Control_OP);
        l_Down_Limit->setObjectName(QStringLiteral("l_Down_Limit"));
        l_Down_Limit->setGeometry(QRect(50, 100, 21, 16));
        QFont font5;
        font5.setPointSize(10);
        l_Down_Limit->setFont(font5);
        l_Upper_limit = new QLabel(t_Control_OP);
        l_Upper_limit->setObjectName(QStringLiteral("l_Upper_limit"));
        l_Upper_limit->setGeometry(QRect(140, 100, 21, 16));
        l_Upper_limit->setFont(font5);
        tb_Upper_Limit = new QLineEdit(t_Control_OP);
        tb_Upper_Limit->setObjectName(QStringLiteral("tb_Upper_Limit"));
        tb_Upper_Limit->setGeometry(QRect(160, 100, 41, 21));
        l_OP_Mode = new QLabel(t_Control_OP);
        l_OP_Mode->setObjectName(QStringLiteral("l_OP_Mode"));
        l_OP_Mode->setGeometry(QRect(20, 150, 141, 16));
        l_OP_Mode->setFont(font);
        comboBox = new QComboBox(t_Control_OP);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 150, 79, 22));
        l_GOP_Mode = new QLabel(t_Control_OP);
        l_GOP_Mode->setObjectName(QStringLiteral("l_GOP_Mode"));
        l_GOP_Mode->setGeometry(QRect(20, 190, 191, 16));
        l_GOP_Mode->setFont(font);
        cb_GOP_Mode = new QComboBox(t_Control_OP);
        cb_GOP_Mode->setObjectName(QStringLiteral("cb_GOP_Mode"));
        cb_GOP_Mode->setGeometry(QRect(220, 190, 79, 22));
        b_Apply_Changes_GOP = new QPushButton(t_Control_OP);
        b_Apply_Changes_GOP->setObjectName(QStringLiteral("b_Apply_Changes_GOP"));
        b_Apply_Changes_GOP->setGeometry(QRect(340, 190, 71, 22));
        b_Edit_tControl = new QPushButton(t_Control_OP);
        b_Edit_tControl->setObjectName(QStringLiteral("b_Edit_tControl"));
        b_Edit_tControl->setGeometry(QRect(570, 30, 81, 41));
        cb_O_Mode->addTab(t_Control_OP, QString());
        t_Graph = new QWidget();
        t_Graph->setObjectName(QStringLiteral("t_Graph"));
        cb_O_Mode->addTab(t_Graph, QString());
        l_ID_Module = new QLabel(centralWidget);
        l_ID_Module->setObjectName(QStringLiteral("l_ID_Module"));
        l_ID_Module->setGeometry(QRect(30, 10, 131, 16));
        QFont font6;
        font6.setPointSize(11);
        l_ID_Module->setFont(font6);
        l_Position_Module = new QLabel(centralWidget);
        l_Position_Module->setObjectName(QStringLiteral("l_Position_Module"));
        l_Position_Module->setGeometry(QRect(30, 30, 91, 16));
        l_Position_Module->setFont(font);
        b_Apply_Changes = new QPushButton(centralWidget);
        b_Apply_Changes->setObjectName(QStringLiteral("b_Apply_Changes"));
        b_Apply_Changes->setGeometry(QRect(530, 20, 181, 31));
        l_Sensor_Type = new QLabel(centralWidget);
        l_Sensor_Type->setObjectName(QStringLiteral("l_Sensor_Type"));
        l_Sensor_Type->setGeometry(QRect(30, 50, 171, 16));
        l_Sensor_Type->setFont(font);
        m_monitron_0_0->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(m_monitron_0_0);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 740, 19));
        m_monitron_0_0->setMenuBar(menuBar);
        mainToolBar = new QToolBar(m_monitron_0_0);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        m_monitron_0_0->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(m_monitron_0_0);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        m_monitron_0_0->setStatusBar(statusBar);

        retranslateUi(m_monitron_0_0);

        cb_O_Mode->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(m_monitron_0_0);
    } // setupUi

    void retranslateUi(QMainWindow *m_monitron_0_0)
    {
        m_monitron_0_0->setWindowTitle(QApplication::translate("m_monitron_0_0", "Mini Monitron V0.0", 0));
        l_Lecture->setText(QApplication::translate("m_monitron_0_0", "Lecture:", 0));
        l_Setpoint->setText(QApplication::translate("m_monitron_0_0", "Setpoint:", 0));
        l_Taux_Var->setText(QApplication::translate("m_monitron_0_0", "Taux de variation:", 0));
        b_Edit_tLecture->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        l_Current_Setpoint->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        l_Current_Var_Rate->setText(QApplication::translate("m_monitron_0_0", "0.00", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Lecture), QApplication::translate("m_monitron_0_0", "Lecture", 0));
        l_StartCycles->setText(QApplication::translate("m_monitron_0_0", "Start Cycles: ", 0));
        l_Cycle1->setText(QApplication::translate("m_monitron_0_0", "Cycle 1:", 0));
        l_Cycle2->setText(QApplication::translate("m_monitron_0_0", "Cycle 2:", 0));
        l_Setpoint_Cycle_2->setText(QApplication::translate("m_monitron_0_0", "Setpoint 2:", 0));
        l_Setpoint_Cycle_1->setText(QApplication::translate("m_monitron_0_0", "Setpoint 1:", 0));
        b_Edit_tCycles->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Cycles), QApplication::translate("m_monitron_0_0", "Cycles", 0));
        l_Lecture_mV->setText(QApplication::translate("m_monitron_0_0", "Lecture (mV):", 0));
        gb_Point1->setTitle(QApplication::translate("m_monitron_0_0", "Point de calibration 1", 0));
        l_P1_mV->setText(QApplication::translate("m_monitron_0_0", "Valeur (mV):", 0));
        l_P1_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Valeur convertie:", 0));
        gb_Point2->setTitle(QApplication::translate("m_monitron_0_0", "Point de calibration 2", 0));
        l_P2_mV->setText(QApplication::translate("m_monitron_0_0", "Valeur (mV):", 0));
        l_P2_Convert_Unit->setText(QApplication::translate("m_monitron_0_0", "Valeur convertie:", 0));
        b_Edit_tCalibration->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Calibration), QApplication::translate("m_monitron_0_0", "Calibration", 0));
        l_COntrol_Range->setText(QApplication::translate("m_monitron_0_0", "Control range:", 0));
        l_Alarm_Range->setText(QApplication::translate("m_monitron_0_0", "Safe operation range:", 0));
        l_Down_Limit->setText(QApplication::translate("m_monitron_0_0", "De:", 0));
        l_Upper_limit->setText(QApplication::translate("m_monitron_0_0", "\303\200:", 0));
        l_OP_Mode->setText(QApplication::translate("m_monitron_0_0", "Operation Mode:", 0));
        l_GOP_Mode->setText(QApplication::translate("m_monitron_0_0", "Global Operation Mode:", 0));
        b_Apply_Changes_GOP->setText(QApplication::translate("m_monitron_0_0", "Apply", 0));
        b_Edit_tControl->setText(QApplication::translate("m_monitron_0_0", "Edit", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Control_OP), QApplication::translate("m_monitron_0_0", "Controle et OP", 0));
        cb_O_Mode->setTabText(cb_O_Mode->indexOf(t_Graph), QApplication::translate("m_monitron_0_0", "Graph", 0));
        l_ID_Module->setText(QApplication::translate("m_monitron_0_0", "Nom:", 0));
        l_Position_Module->setText(QApplication::translate("m_monitron_0_0", "Position:", 0));
        b_Apply_Changes->setText(QApplication::translate("m_monitron_0_0", "Appliquer les changements", 0));
        l_Sensor_Type->setText(QApplication::translate("m_monitron_0_0", "Type de capteur:", 0));
    } // retranslateUi

};

namespace Ui {
    class m_monitron_0_0: public Ui_m_monitron_0_0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_MONITRON_0_0_H
