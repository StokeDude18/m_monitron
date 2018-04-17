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
   // EditLine(const QString & contents, QWidget * parent = 0);
signals:
    void focussed(bool hasFocus);

protected:
    virtual void focusInEvent(QFocusEvent* e);
    virtual void focusOutEvent(QFocusEvent *e);
};


#endif // EDITLINE_H
