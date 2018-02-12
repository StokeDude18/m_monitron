/********************************************************************************
** Form generated from reading UI file 'edit_control_op.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_CONTROL_OP_H
#define UI_EDIT_CONTROL_OP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_edit_Control_OP
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *l_Alarm_Range;
    QLineEdit *tb_Upper_Limit;
    QLabel *l_Upper_limit;
    QLabel *l_Down_Limit;
    QLabel *l_COntrol_Range;
    QLabel *l_GOP_Mode;
    QLineEdit *tb_Control_Range;
    QLineEdit *tb_Lowe_Limit;
    QComboBox *cb_GOP_Mode;
    QLabel *l_OP_Mode;
    QComboBox *comboBox;

    void setupUi(QDialog *edit_Control_OP)
    {
        if (edit_Control_OP->objectName().isEmpty())
            edit_Control_OP->setObjectName(QStringLiteral("edit_Control_OP"));
        edit_Control_OP->resize(565, 400);
        QFont font;
        font.setPointSize(16);
        edit_Control_OP->setFont(font);
        buttonBox = new QDialogButtonBox(edit_Control_OP);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(200, 305, 181, 46));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        l_Alarm_Range = new QLabel(edit_Control_OP);
        l_Alarm_Range->setObjectName(QStringLiteral("l_Alarm_Range"));
        l_Alarm_Range->setGeometry(QRect(75, 85, 211, 26));
        l_Alarm_Range->setFont(font);
        tb_Upper_Limit = new QLineEdit(edit_Control_OP);
        tb_Upper_Limit->setObjectName(QStringLiteral("tb_Upper_Limit"));
        tb_Upper_Limit->setGeometry(QRect(295, 125, 56, 26));
        tb_Upper_Limit->setFont(font);
        l_Upper_limit = new QLabel(edit_Control_OP);
        l_Upper_limit->setObjectName(QStringLiteral("l_Upper_limit"));
        l_Upper_limit->setGeometry(QRect(270, 125, 26, 21));
        QFont font1;
        font1.setPointSize(13);
        l_Upper_limit->setFont(font1);
        l_Down_Limit = new QLabel(edit_Control_OP);
        l_Down_Limit->setObjectName(QStringLiteral("l_Down_Limit"));
        l_Down_Limit->setGeometry(QRect(115, 125, 46, 21));
        l_Down_Limit->setFont(font1);
        l_COntrol_Range = new QLabel(edit_Control_OP);
        l_COntrol_Range->setObjectName(QStringLiteral("l_COntrol_Range"));
        l_COntrol_Range->setGeometry(QRect(75, 35, 146, 26));
        QFont font2;
        font2.setPointSize(16);
        font2.setItalic(false);
        l_COntrol_Range->setFont(font2);
        l_GOP_Mode = new QLabel(edit_Control_OP);
        l_GOP_Mode->setObjectName(QStringLiteral("l_GOP_Mode"));
        l_GOP_Mode->setGeometry(QRect(80, 240, 231, 26));
        l_GOP_Mode->setFont(font);
        tb_Control_Range = new QLineEdit(edit_Control_OP);
        tb_Control_Range->setObjectName(QStringLiteral("tb_Control_Range"));
        tb_Control_Range->setGeometry(QRect(270, 35, 156, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setItalic(true);
        tb_Control_Range->setFont(font3);
        tb_Lowe_Limit = new QLineEdit(edit_Control_OP);
        tb_Lowe_Limit->setObjectName(QStringLiteral("tb_Lowe_Limit"));
        tb_Lowe_Limit->setGeometry(QRect(165, 125, 51, 26));
        tb_Lowe_Limit->setFont(font);
        cb_GOP_Mode = new QComboBox(edit_Control_OP);
        cb_GOP_Mode->setObjectName(QStringLiteral("cb_GOP_Mode"));
        cb_GOP_Mode->setGeometry(QRect(315, 235, 101, 31));
        cb_GOP_Mode->setFont(font);
        l_OP_Mode = new QLabel(edit_Control_OP);
        l_OP_Mode->setObjectName(QStringLiteral("l_OP_Mode"));
        l_OP_Mode->setGeometry(QRect(80, 185, 176, 21));
        l_OP_Mode->setFont(font);
        comboBox = new QComboBox(edit_Control_OP);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(315, 180, 101, 31));
        comboBox->setFont(font);

        retranslateUi(edit_Control_OP);
        QObject::connect(buttonBox, SIGNAL(accepted()), edit_Control_OP, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), edit_Control_OP, SLOT(reject()));

        QMetaObject::connectSlotsByName(edit_Control_OP);
    } // setupUi

    void retranslateUi(QDialog *edit_Control_OP)
    {
        edit_Control_OP->setWindowTitle(QApplication::translate("edit_Control_OP", "Dialog", 0));
        l_Alarm_Range->setText(QApplication::translate("edit_Control_OP", "Safe operation range:", 0));
        l_Upper_limit->setText(QApplication::translate("edit_Control_OP", "To:", 0));
        l_Down_Limit->setText(QApplication::translate("edit_Control_OP", "From:", 0));
        l_COntrol_Range->setText(QApplication::translate("edit_Control_OP", "Control range:", 0));
        l_GOP_Mode->setText(QApplication::translate("edit_Control_OP", "Global Operation Mode:", 0));
        l_OP_Mode->setText(QApplication::translate("edit_Control_OP", "Operation Mode:", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_Control_OP: public Ui_edit_Control_OP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_CONTROL_OP_H
