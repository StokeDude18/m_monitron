/********************************************************************************
** Form generated from reading UI file 'edit_lecture.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_LECTURE_H
#define UI_EDIT_LECTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_edit_Lecture
{
public:
    QLabel *l_Setpoint;
    QLineEdit *tb_new_var_rate;
    QDialogButtonBox *buttonBox;
    QLineEdit *tb_new_setpoint;
    QLabel *l_Var_Rate;

    void setupUi(QDialog *edit_Lecture)
    {
        if (edit_Lecture->objectName().isEmpty())
            edit_Lecture->setObjectName(QStringLiteral("edit_Lecture"));
        edit_Lecture->resize(698, 440);
        l_Setpoint = new QLabel(edit_Lecture);
        l_Setpoint->setObjectName(QStringLiteral("l_Setpoint"));
        l_Setpoint->setGeometry(QRect(95, 80, 231, 36));
        QFont font;
        font.setPointSize(24);
        l_Setpoint->setFont(font);
        tb_new_var_rate = new QLineEdit(edit_Lecture);
        tb_new_var_rate->setObjectName(QStringLiteral("tb_new_var_rate"));
        tb_new_var_rate->setGeometry(QRect(415, 170, 156, 36));
        QFont font1;
        font1.setPointSize(20);
        tb_new_var_rate->setFont(font1);
        buttonBox = new QDialogButtonBox(edit_Lecture);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(225, 280, 231, 71));
        buttonBox->setFont(font1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        tb_new_setpoint = new QLineEdit(edit_Lecture);
        tb_new_setpoint->setObjectName(QStringLiteral("tb_new_setpoint"));
        tb_new_setpoint->setGeometry(QRect(415, 80, 156, 36));
        tb_new_setpoint->setFont(font1);
        tb_new_setpoint->setInputMethodHints(Qt::ImhNone);
        l_Var_Rate = new QLabel(edit_Lecture);
        l_Var_Rate->setObjectName(QStringLiteral("l_Var_Rate"));
        l_Var_Rate->setGeometry(QRect(95, 170, 311, 36));
        l_Var_Rate->setFont(font);

        retranslateUi(edit_Lecture);
        QObject::connect(buttonBox, SIGNAL(accepted()), edit_Lecture, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), edit_Lecture, SLOT(reject()));

        QMetaObject::connectSlotsByName(edit_Lecture);
    } // setupUi

    void retranslateUi(QDialog *edit_Lecture)
    {
        edit_Lecture->setWindowTitle(QApplication::translate("edit_Lecture", "Reading params edit", 0));
        l_Setpoint->setText(QApplication::translate("edit_Lecture", "New Setpoint:", 0));
        tb_new_setpoint->setInputMask(QString());
        l_Var_Rate->setText(QApplication::translate("edit_Lecture", "New Variation rate:", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_Lecture: public Ui_edit_Lecture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_LECTURE_H
