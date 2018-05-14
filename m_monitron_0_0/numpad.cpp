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

//Constructeur recevant un bool pour faire afficher ou non le bouton point (.)
Numpad::Numpad(bool floatValuesEnabled, QWidget *parent) : QDialog(parent), ui(new Ui::Numpad)
{
    ui->setupUi(this);

    //Ajoute un validateur au textbox du numpad
    ui->le_Entry->setValidator(new QDoubleValidator(0,1000, 2));
    QFont font;

    /*Ajoute un gestionnaire de signaux pour permettre d'assigner un signal
      comportant un paramètre à un signal n'en comportant pas.
      EX: signal digitClicked(int) et clicked() */
    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(digitClicked(int)));

    /*Pour les boutons 0 à 9 du numpad, définit le texte du bouton et lui
      assigne un signal à émettre lors d'un événement clic*/
    for(int i = 0; i < 10; i++)
    {
        QString text = QString::number(i);
        buttons[i] = new QPushButton(text, this);
        signalMapper->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }

    //Définit le texte du bouton point (.) et lui assigne un signal
    buttons[DOT] = new QPushButton(".", this);
    signalMapper->setMapping(buttons[DOT], 10);
    connect(buttons[DOT], SIGNAL(clicked()), signalMapper, SLOT(map()));

    //Définit le texte du bouton Backspace et lui assigne un signal
    buttons[BACK] = new QPushButton("Back", this);
    signalMapper->setMapping(buttons[BACK], 11);
    connect(buttons[BACK], SIGNAL(clicked()), signalMapper, SLOT(map()));

    //Grossit le texte de tous les boutons
    for(auto &i_button: buttons)
    {
        font = i_button->font();
        font.setPointSize(16);
        i_button->setFont(font);
    }

    createLayout();//Fonction d'organisation graphique du numpad (disposition des éléments)

    /*Connecte le signal digitClicked(int), maintenant généré quand un bouton du numpad est cliqué,
      à la "slot" onPadClick qui fait la gestion de l'événement en fonction du bouton enfoncé*/
    connect(this, SIGNAL(digitClicked(int)), this, SLOT(onPadClick(int)));

    //Désactive le point si le champ générant le numpad ne permet pas les valeurs non entières
    if(floatValuesEnabled == false)
        buttons[DOT]->setVisible(false);
}

Numpad::~Numpad()
{
    delete ui;
}

//"Slot" appelée quand un bouton du numpad est cliqué
void Numpad::onPadClick(int digit)
{
    switch(digit)
    {
    case 0 ... 9://Si bouton 0 à 9, ajoute le chiffre au champ
        ui->le_Entry->setText(ui->le_Entry->text() + QString::number(digit));
        break;
    case DOT://Si point, ajoute un point au champ, mais seulement si le champ n'en comporte pas déjà un
        if(!ui->le_Entry->text().contains('.'))
            ui->le_Entry->setText(ui->le_Entry->text() + '.');
        break;
    case BACK://Efface le dernier caractère entré dans le champ
        ui->le_Entry->backspace();
        break;
    }
}

//Méthode utilisée pour générer l'organisation graphique du numpad
void Numpad::createLayout()
{
    QGridLayout *layout = new QGridLayout();

    //Définit la police d'expansion des boutons du numpad pour qu'ils prennest le plus d'esapce possible dans la grille
    for(auto &i_button: buttons)
        i_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //Définit l'espace entre les boutons
    layout->setMargin(6);
    layout->setSpacing(6);

    //Dispose les boutons 1 à 9
    for(int i = 0; i < 9; i++)
        layout->addWidget(buttons[i+1], 2- i/3 , i%3);

    //Dispose les boutons point (.), 0 et backspace au bas du numpad
    layout->addWidget(buttons[0], 3, 1);
    layout->addWidget(buttons[DOT],3,0);
    layout->addWidget(buttons[BACK],3,2);

    ui->VL->addLayout(layout);//Ajoute la grille de boutons au layout de la fenêtre
}

