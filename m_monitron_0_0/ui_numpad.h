/********************************************************************************
** Form generated from reading UI file 'numpad.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMPAD_H
#define UI_NUMPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Numpad
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *VL;
    QDialogButtonBox *buttonBox;
    QLineEdit *le_Entry;
    QLabel *l_Val_mV;
    QLabel *l_mV;

    void setupUi(QDialog *Numpad)
    {
        if (Numpad->objectName().isEmpty())
            Numpad->setObjectName(QStringLiteral("Numpad"));
        Numpad->resize(430, 455);
        verticalLayoutWidget = new QWidget(Numpad);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 80, 426, 306));
        VL = new QVBoxLayout(verticalLayoutWidget);
        VL->setObjectName(QStringLiteral("VL"));
        VL->setSizeConstraint(QLayout::SetDefaultConstraint);
        VL->setContentsMargins(20, 10, 20, 10);
        buttonBox = new QDialogButtonBox(Numpad);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(135, 405, 171, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        le_Entry = new QLineEdit(Numpad);
        le_Entry->setObjectName(QStringLiteral("le_Entry"));
        le_Entry->setGeometry(QRect(10, 10, 411, 36));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        le_Entry->setFont(font1);
        l_Val_mV = new QLabel(Numpad);
        l_Val_mV->setObjectName(QStringLiteral("l_Val_mV"));
        l_Val_mV->setEnabled(true);
        l_Val_mV->setGeometry(QRect(225, 55, 111, 26));
        QFont font2;
        font2.setPointSize(12);
        l_Val_mV->setFont(font2);
        l_mV = new QLabel(Numpad);
        l_mV->setObjectName(QStringLiteral("l_mV"));
        l_mV->setEnabled(true);
        l_mV->setGeometry(QRect(140, 55, 76, 26));
        l_mV->setFont(font2);

        retranslateUi(Numpad);
        QObject::connect(buttonBox, SIGNAL(accepted()), Numpad, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Numpad, SLOT(reject()));

        QMetaObject::connectSlotsByName(Numpad);
    } // setupUi

    void retranslateUi(QDialog *Numpad)
    {
        Numpad->setWindowTitle(QApplication::translate("Numpad", "Numpad", 0));
        l_Val_mV->setText(QString());
        l_mV->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Numpad: public Ui_Numpad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMPAD_H
