/*	File:	editline.h
 *	Author:	Alfred M.-Quintin
 *	Date:	Mai. 2018
 *
 *	Brief:	Fichier contenant les prototypes des fonctions utilisées par la
 *          classe EditLine. Il est à noter que cette classe hérite de la classe
 *          QLineEdit et ajoute comme fonctionnalité la gestion de prise de focus
 *          du champ de texte.
 *
 */

#ifndef EDITLINE_H
#define EDITLINE_H

#include <QLineEdit>
#include <QWidget>

/*namespace Ui {
class EditLine;
}
*/
class EditLine : public QLineEdit
{
    Q_OBJECT

public:
    EditLine(QWidget * parent = 0);
    ~EditLine();
signals:
    void focussed(bool hasFocus);

protected:

    virtual void focusInEvent(QFocusEvent* e);    
};


#endif // EDITLINE_H
