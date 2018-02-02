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

class Ui_Settings_Edit
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *l_Setpoint;
    QLineEdit *tb_new_setpoint;
    QLineEdit *tb_new_var_rate;
    QLabel *l_Var_Rate;

    void setupUi(QDialog *Settings_Edit)
    {
        if (Settings_Edit->objectName().isEmpty())
            Settings_Edit->setObjectName(QStringLiteral("Settings_Edit"));
        Settings_Edit->resize(400, 300);
        buttonBox = new QDialogButtonBox(Settings_Edit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        l_Setpoint = new QLabel(Settings_Edit);
        l_Setpoint->setObjectName(QStringLiteral("l_Setpoint"));
        l_Setpoint->setGeometry(QRect(20, 60, 111, 16));
        QFont font;
        font.setPointSize(12);
        l_Setpoint->setFont(font);
        tb_new_setpoint = new QLineEdit(Settings_Edit);
        tb_new_setpoint->setObjectName(QStringLiteral("tb_new_setpoint"));
        tb_new_setpoint->setGeometry(QRect(180, 60, 113, 22));
        tb_new_setpoint->setInputMethodHints(Qt::ImhNone);
        tb_new_var_rate = new QLineEdit(Settings_Edit);
        tb_new_var_rate->setObjectName(QStringLiteral("tb_new_var_rate"));
        tb_new_var_rate->setGeometry(QRect(180, 130, 113, 22));
        l_Var_Rate = new QLabel(Settings_Edit);
        l_Var_Rate->setObjectName(QStringLiteral("l_Var_Rate"));
        l_Var_Rate->setGeometry(QRect(20, 130, 161, 16));
        l_Var_Rate->setFont(font);

        retranslateUi(Settings_Edit);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings_Edit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings_Edit, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings_Edit);
    } // setupUi

    void retranslateUi(QDialog *Settings_Edit)
    {
        Settings_Edit->setWindowTitle(QApplication::translate("Settings_Edit", "Edit Setpoint/Variation settings", 0));
        l_Setpoint->setText(QApplication::translate("Settings_Edit", "New Setpoint:", 0));
        tb_new_setpoint->setInputMask(QString());
        l_Var_Rate->setText(QApplication::translate("Settings_Edit", "New Variation rate:", 0));
    } // retranslateUi

};

namespace Ui {
    class Settings_Edit: public Ui_Settings_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_LECTURE_H
