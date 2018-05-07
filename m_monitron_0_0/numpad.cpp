#include "numpad.h"
#include "ui_numpad.h"
#include <QSignalMapper>

#include <QtWidgets>
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <exception>
#include <QtGui>
#include <QString>
#include <QRect>

//Constructeur par défaut, ne pas utiliser
Numpad::Numpad(QWidget *parent) : QDialog(parent), ui(new Ui::Numpad)
{
    ui->setupUi(this);
}

Numpad::Numpad(bool floatValuesEnabled, QWidget *parent) : QDialog(parent), ui(new Ui::Numpad)
{
    ui->setupUi(this);

    ui->le_Entry->setValidator(new QDoubleValidator(0,1000, 2));
    QFont font;


    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(digitClicked(int)));
    for(int i = 0; i < 10; i++)
    {
        QString text = QString::number(i);
        buttons[i] = new QPushButton(text, this);
        signalMapper->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }

    buttons[DOT] = new QPushButton(".", this);
    signalMapper->setMapping(buttons[DOT], 10);
    connect(buttons[DOT], SIGNAL(clicked()), signalMapper, SLOT(map()));

    buttons[BACK] = new QPushButton("Back", this);
    signalMapper->setMapping(buttons[BACK], 11);
    connect(buttons[BACK], SIGNAL(clicked()), signalMapper, SLOT(map()));

    for(auto &i_button: buttons)
    {
        font = i_button->font();
        font.setPointSize(16);
        i_button->setFont(font);
    }

    createLayout();
    connect(this, SIGNAL(digitClicked(int)), this, SLOT(onPadClick(int)));
    if(floatValuesEnabled == false)
        buttons[DOT]->setVisible(false);
}

Numpad::~Numpad()
{
    delete ui;
}

void Numpad::onPadClick(int digit)
{
    switch(digit)
    {
    case 0 ... 9:
        ui->le_Entry->setText(ui->le_Entry->text() + QString::number(digit));
        break;
    case DOT:
        if(!ui->le_Entry->text().contains('.'))
            ui->le_Entry->setText(ui->le_Entry->text() + '.');
        break;
    case BACK:
        //ui->le_Entry->setText(ui->le_Entry->text() + '\b');
        ui->le_Entry->backspace();
        break;
    }
}

void Numpad::createLayout()
{
    QGridLayout *layout = new QGridLayout();
    for(auto &i_button: buttons)
        i_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    layout->setMargin(6);
    layout->setSpacing(6);

    for(int i = 0; i < 9; i++)
        layout->addWidget(buttons[i+1], 2- i/3 , i%3);

    layout->addWidget(buttons[0], 3, 1);
    layout->addWidget(buttons[DOT],3,0);
    layout->addWidget(buttons[BACK],3,2);

    ui->VL->addLayout(layout);
}

