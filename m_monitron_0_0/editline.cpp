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

void EditLine::focusInEvent(QFocusEvent *e)
{
    QLineEdit::focusInEvent(e);
    if(e->reason() == Qt::MouseFocusReason)
        emit(focussed(true));
}

void EditLine::focusOutEvent(QFocusEvent *e)
{
    QLineEdit::focusOutEvent(e);
    if(e->reason() == Qt::MouseFocusReason)
        emit(focussed(false));
}



