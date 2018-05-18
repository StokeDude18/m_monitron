#include "editline.h"
#include <QLineEdit>
#include "numpad.h"
#include "ui_numpad.h"
#include <QDialog>
#include <QFocusEvent>

EditLine::EditLine(QWidget * parent) : QLineEdit(parent)
{

}

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





