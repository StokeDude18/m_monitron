#ifndef EDIT_LECTURE_H
#define EDIT_LECTURE_H
#include "ui_edit_lecture.h"
#include <QDialog>
#include "numpad.h"

namespace Ui {
class edit_Lecture;
}

class edit_Lecture : public QDialog
{
    Q_OBJECT

public:
    explicit edit_Lecture(QWidget *parent = 0);
    ~edit_Lecture();
    Ui::edit_Lecture *ui;//Pointeur vers la fenêtre graphique edit_lecture.ui

private slots:
    void onFocus(bool hasFocus);

private:
};



#endif // EDIT_LECTURE_H
