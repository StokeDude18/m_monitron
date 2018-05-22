/*	File:	editline.cpp
 *	Author:	Alfred M.-Quintin
 *	Date:	Mai 2018
 *
 *	Brief:	Fichier contenant la méthode surchargée "focusInEvent" qui
 *          est appelée quand le focus est pris par un champ d'édition
 *          de type QLineEdit.
 *
 */

#include "editline.h"
#include <QLineEdit>
#include "numpad.h"
#include "ui_numpad.h"
#include <QDialog>
#include <QFocusEvent>

//Constructeur
EditLine::EditLine(QWidget * parent) : QLineEdit(parent)
{

}

//Destructeur
EditLine::~EditLine()
{

}

//Méthode appelée quand le textbox prend le focus
void EditLine::focusInEvent(QFocusEvent *e)
{
    QLineEdit::focusInEvent(e);
    if(e->reason() == Qt::MouseFocusReason)//Si l'événement de prise de focus est généré par la souris (clic)
        emit(focussed(true));//Émet le signal focussed
}





