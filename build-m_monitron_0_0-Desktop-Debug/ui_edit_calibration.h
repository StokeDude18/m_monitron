/********************************************************************************
** Form generated from reading UI file 'edit_calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_CALIBRATION_H
#define UI_EDIT_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_edit_Calibration
{
public:
    QDialogButtonBox *buttonBox;
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

    void setupUi(QDialog *edit_Calibration)
    {
        if (edit_Calibration->objectName().isEmpty())
            edit_Calibration->setObjectName(QStringLiteral("edit_Calibration"));
        edit_Calibration->resize(496, 434);
        buttonBox = new QDialogButtonBox(edit_Calibration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 370, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gb_Point1 = new QGroupBox(edit_Calibration);
        gb_Point1->setObjectName(QStringLiteral("gb_Point1"));
        gb_Point1->setGeometry(QRect(105, 50, 301, 121));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        gb_Point1->setFont(font);
        l_P1_mV = new QLabel(gb_Point1);
        l_P1_mV->setObjectName(QStringLiteral("l_P1_mV"));
        l_P1_mV->setGeometry(QRect(10, 50, 111, 16));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        l_P1_mV->setFont(font1);
        tb_P1_mV = new QLineEdit(gb_Point1);
        tb_P1_mV->setObjectName(QStringLiteral("tb_P1_mV"));
        tb_P1_mV->setGeometry(QRect(150, 50, 131, 21));
        l_P1_Convert_Unit = new QLabel(gb_Point1);
        l_P1_Convert_Unit->setObjectName(QStringLiteral("l_P1_Convert_Unit"));
        l_P1_Convert_Unit->setGeometry(QRect(10, 90, 131, 16));
        l_P1_Convert_Unit->setFont(font1);
        tb_P1Convert_Unit = new QLineEdit(gb_Point1);
        tb_P1Convert_Unit->setObjectName(QStringLiteral("tb_P1Convert_Unit"));
        tb_P1Convert_Unit->setGeometry(QRect(150, 90, 131, 21));
        gb_Point2 = new QGroupBox(edit_Calibration);
        gb_Point2->setObjectName(QStringLiteral("gb_Point2"));
        gb_Point2->setGeometry(QRect(105, 205, 301, 131));
        gb_Point2->setFont(font);
        l_P2_mV = new QLabel(gb_Point2);
        l_P2_mV->setObjectName(QStringLiteral("l_P2_mV"));
        l_P2_mV->setGeometry(QRect(10, 50, 111, 16));
        l_P2_mV->setFont(font1);
        tb_P2_mV = new QLineEdit(gb_Point2);
        tb_P2_mV->setObjectName(QStringLiteral("tb_P2_mV"));
        tb_P2_mV->setGeometry(QRect(150, 50, 131, 21));
        l_P2_Convert_Unit = new QLabel(gb_Point2);
        l_P2_Convert_Unit->setObjectName(QStringLiteral("l_P2_Convert_Unit"));
        l_P2_Convert_Unit->setGeometry(QRect(10, 90, 131, 16));
        l_P2_Convert_Unit->setFont(font1);
        tb_P2_Convert_Unit = new QLineEdit(gb_Point2);
        tb_P2_Convert_Unit->setObjectName(QStringLiteral("tb_P2_Convert_Unit"));
        tb_P2_Convert_Unit->setGeometry(QRect(150, 90, 131, 21));

        retranslateUi(edit_Calibration);
        QObject::connect(buttonBox, SIGNAL(accepted()), edit_Calibration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), edit_Calibration, SLOT(reject()));

        QMetaObject::connectSlotsByName(edit_Calibration);
    } // setupUi

    void retranslateUi(QDialog *edit_Calibration)
    {
        edit_Calibration->setWindowTitle(QApplication::translate("edit_Calibration", "Linear sensor reading calibration", 0));
        gb_Point1->setTitle(QApplication::translate("edit_Calibration", "Calibration point #1", 0));
        l_P1_mV->setText(QApplication::translate("edit_Calibration", "Raw value (mV):", 0));
        l_P1_Convert_Unit->setText(QApplication::translate("edit_Calibration", "Converted value:", 0));
        gb_Point2->setTitle(QApplication::translate("edit_Calibration", "Calibration point #2", 0));
        l_P2_mV->setText(QApplication::translate("edit_Calibration", "Raw value (mV):", 0));
        l_P2_Convert_Unit->setText(QApplication::translate("edit_Calibration", "Converted value:", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_Calibration: public Ui_edit_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_CALIBRATION_H
