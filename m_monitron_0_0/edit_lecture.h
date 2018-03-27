#ifndef EDIT_LECTURE_H
#define EDIT_LECTURE_H

#include <QDialog>

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

private:


};

#endif // EDIT_LECTURE_H
