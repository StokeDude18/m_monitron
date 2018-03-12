/********************************************************************************
** Form generated from reading UI file 'edit_cycles.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_CYCLES_H
#define UI_EDIT_CYCLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_edit_Cycles
{
public:
    QDialogButtonBox *dialogButtonBox;
    QLineEdit *tb_Setpoint2;
    QLabel *l_Cycle1_2;
    QLineEdit *tb_Cycle2;
    QLineEdit *tb_Setpoint1;
    QLabel *l_Setpoint_Cycle_3;
    QLabel *l_Cycle2_2;
    QLineEdit *tb_Cycle1;
    QLabel *l_Setpoint_Cycle_4;
    QCheckBox *cb_Cycle_Mode_Toggle;

    void setupUi(QDialog *edit_Cycles)
    {
        if (edit_Cycles->objectName().isEmpty())
            edit_Cycles->setObjectName(QStringLiteral("edit_Cycles"));
        edit_Cycles->resize(581, 444);
        QFont font;
        font.setPointSize(14);
        edit_Cycles->setFont(font);
        dialogButtonBox = new QDialogButtonBox(edit_Cycles);
        dialogButtonBox->setObjectName(QStringLiteral("dialogButtonBox"));
        dialogButtonBox->setGeometry(QRect(190, 380, 181, 32));
        dialogButtonBox->setOrientation(Qt::Horizontal);
        dialogButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tb_Setpoint2 = new QLineEdit(edit_Cycles);
        tb_Setpoint2->setObjectName(QStringLiteral("tb_Setpoint2"));
        tb_Setpoint2->setGeometry(QRect(370, 190, 141, 22));
        l_Cycle1_2 = new QLabel(edit_Cycles);
        l_Cycle1_2->setObjectName(QStringLiteral("l_Cycle1_2"));
        l_Cycle1_2->setGeometry(QRect(30, 110, 76, 16));
        l_Cycle1_2->setFont(font);
        tb_Cycle2 = new QLineEdit(edit_Cycles);
        tb_Cycle2->setObjectName(QStringLiteral("tb_Cycle2"));
        tb_Cycle2->setGeometry(QRect(110, 190, 141, 22));
        tb_Setpoint1 = new QLineEdit(edit_Cycles);
        tb_Setpoint1->setObjectName(QStringLiteral("tb_Setpoint1"));
        tb_Setpoint1->setGeometry(QRect(370, 110, 141, 22));
        l_Setpoint_Cycle_3 = new QLabel(edit_Cycles);
        l_Setpoint_Cycle_3->setObjectName(QStringLiteral("l_Setpoint_Cycle_3"));
        l_Setpoint_Cycle_3->setGeometry(QRect(260, 190, 111, 16));
        l_Setpoint_Cycle_3->setFont(font);
        l_Cycle2_2 = new QLabel(edit_Cycles);
        l_Cycle2_2->setObjectName(QStringLiteral("l_Cycle2_2"));
        l_Cycle2_2->setGeometry(QRect(30, 190, 81, 16));
        l_Cycle2_2->setFont(font);
        tb_Cycle1 = new QLineEdit(edit_Cycles);
        tb_Cycle1->setObjectName(QStringLiteral("tb_Cycle1"));
        tb_Cycle1->setGeometry(QRect(110, 110, 141, 22));
        l_Setpoint_Cycle_4 = new QLabel(edit_Cycles);
        l_Setpoint_Cycle_4->setObjectName(QStringLiteral("l_Setpoint_Cycle_4"));
        l_Setpoint_Cycle_4->setGeometry(QRect(260, 110, 111, 16));
        l_Setpoint_Cycle_4->setFont(font);
        cb_Cycle_Mode_Toggle = new QCheckBox(edit_Cycles);
        cb_Cycle_Mode_Toggle->setObjectName(QStringLiteral("cb_Cycle_Mode_Toggle"));
        cb_Cycle_Mode_Toggle->setGeometry(QRect(15, 50, 236, 22));
        cb_Cycle_Mode_Toggle->setLayoutDirection(Qt::RightToLeft);

        retranslateUi(edit_Cycles);
        QObject::connect(dialogButtonBox, SIGNAL(accepted()), edit_Cycles, SLOT(accept()));
        QObject::connect(dialogButtonBox, SIGNAL(rejected()), edit_Cycles, SLOT(reject()));

        QMetaObject::connectSlotsByName(edit_Cycles);
    } // setupUi

    void retranslateUi(QDialog *edit_Cycles)
    {
        edit_Cycles->setWindowTitle(QApplication::translate("edit_Cycles", "Edit cycles settings", 0));
        l_Cycle1_2->setText(QApplication::translate("edit_Cycles", "Cycle 1:", 0));
        l_Setpoint_Cycle_3->setText(QApplication::translate("edit_Cycles", "Setpoint 2:", 0));
        l_Cycle2_2->setText(QApplication::translate("edit_Cycles", "Cycle 2:", 0));
        l_Setpoint_Cycle_4->setText(QApplication::translate("edit_Cycles", "Setpoint 1:", 0));
        cb_Cycle_Mode_Toggle->setText(QApplication::translate("edit_Cycles", "Cycles mode enabled", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_Cycles: public Ui_edit_Cycles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_CYCLES_H
