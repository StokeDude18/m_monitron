/********************************************************************************
** Form generated from reading UI file 'numpad.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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

    void setupUi(QDialog *Numpad)
    {
        if (Numpad->objectName().isEmpty())
            Numpad->setObjectName(QStringLiteral("Numpad"));
        Numpad->resize(430, 455);
        verticalLayoutWidget = new QWidget(Numpad);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 75, 426, 311));
        VL = new QVBoxLayout(verticalLayoutWidget);
        VL->setObjectName(QStringLiteral("VL"));
        VL->setSizeConstraint(QLayout::SetDefaultConstraint);
        VL->setContentsMargins(20, 10, 20, 10);
        buttonBox = new QDialogButtonBox(Numpad);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(125, 400, 171, 31));
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
        le_Entry->setGeometry(QRect(9, 25, 411, 36));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        le_Entry->setFont(font1);

        retranslateUi(Numpad);
        QObject::connect(buttonBox, SIGNAL(accepted()), Numpad, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Numpad, SLOT(reject()));

        QMetaObject::connectSlotsByName(Numpad);
    } // setupUi

    void retranslateUi(QDialog *Numpad)
    {
        Numpad->setWindowTitle(QApplication::translate("Numpad", "Numpad", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Numpad: public Ui_Numpad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMPAD_H
